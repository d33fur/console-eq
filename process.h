#pragma once

//#include <juce_audio_processors/juce_audio_processors.h>

#if (MSVC)
#include "ipps.h"
#endif

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class ContentComponent : public juce::Component
{
public:
    ContentComponent();
    ~ContentComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button);
    void ShowPresetsPage();
    void ShowBundlesPage();
    void ShowQuestsPage();
    void ShowHomePage();
    void ShowMyPage();
    void ShowTracksPage();
    void ShowCommunityPage();

private:
    PresetsComponent PresetsPage;
    BundlesComponent BundlesPage;
    QuestsComponent QuestsPage;
    HomeComponent HomePage;
    MyComponent MyPage;
    TracksComponent TracksPage;
    CommunityComponent CommunityPage;



    juce::TextButton Home{ "Logo" }, Presets{ "Library" }, Bundles{ "Bundles" }, Quests{ "Quests" }, Tracks{ "Tracks" }, Community{ "Community" }, My{ "My" };
    juce::Slider Volume;
    std::vector<bool> status{ 1, 0, 0, 0, 0, 0, 0 };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ContentComponent)
};

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    //==============================================================================
    // Your private member variables go here...
    juce::Viewport view;
    ContentComponent content;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

