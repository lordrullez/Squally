#include "Track.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/Events/SoundEvents.h"
#include "Engine/Localization/LocalizedString.h"
#include "Engine/Sound/Music.h"
#include "Engine/Sound/MusicPlayer.h"
#include "Engine/Utils/GameUtils.h"

using namespace cocos2d;

Track::Track(std::string musicResource, LocalizedString* trackName, LocalizedString* artistName) : super()
{
	this->music = Music::createAndAddGlobally(this, musicResource);
	this->trackName = trackName;
	this->artistName = artistName;

	if (this->trackName != nullptr)
	{
		this->addChild(this->trackName);
	}

	if (this->artistName != nullptr)
	{
		this->addChild(this->artistName);
	}
}

Track::~Track()
{
	if (this->music != nullptr)
	{
		MusicPlayer::orphanMusic(this->music);
	}
}

void Track::initializeListeners()
{
	super::initializeListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(SoundEvents::EventOnMusicDestroyed, [=](EventCustom* eventCustom)
	{
		SoundEvents::MusicDestroyedArgs* args = static_cast<SoundEvents::MusicDestroyedArgs*>(eventCustom->getUserData());

		if (args != nullptr && args->music == this->music)
		{
			this->music = nullptr;
		}
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(SoundEvents::EventDestroyOrphanedMusic, [=](EventCustom* eventCustom)
	{
		if (this->music != nullptr && this->music->isOrphaned())
		{
			MusicPlayer::destroyMusic(this->music);
		}
	}));
}

LocalizedString* Track::getTrackName()
{
	return this->trackName == nullptr ? nullptr : this->trackName->clone();
}

LocalizedString* Track::getArtistName()
{
	return this->artistName == nullptr ? nullptr : this->artistName->clone();
}

void Track::push(float delay)
{
	if (this->music != nullptr)
	{
		MusicPlayer::play(this->music, true, delay, false);
	}

	this->defer([=]()
	{
		SoundEvents::TriggerTrackPlayed(SoundEvents::TrackPlayedArgs(this));
	});
}

void Track::play(float delay)
{
	if (this->music != nullptr)
	{
		MusicPlayer::play(this->music, true, delay, true);
	}

	this->defer([=]()
	{
		SoundEvents::TriggerTrackPlayed(SoundEvents::TrackPlayedArgs(this));
	});
}

void Track::pop()
{
	if (this->music != nullptr && MusicPlayer::getCurrentSong() == this->music)
	{
		MusicPlayer::popMusic();
	}
}