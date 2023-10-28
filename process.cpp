#include "process.h"
//==============================================================================
ContentComponent::ContentComponent()
{
    auto size = juce::Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    //setSize (size.getWidth(), size.getHeight());
    setSize(size.getWidth(), 2500);



    addChildComponent(PresetsPage);
    addChildComponent(BundlesPage);
    addChildComponent(QuestsPage);
    addChildComponent(HomePage);
    addChildComponent(MyPage);
    addChildComponent(TracksPage);
    addChildComponent(CommunityPage);



    Presets.setToggleState(true, juce::NotificationType::dontSendNotification);
    Presets.onClick = [this]() {ShowPresetsPage();};
    Bundles.setToggleState(true, juce::NotificationType::dontSendNotification);
    Bundles.onClick = [this]() {ShowBundlesPage();};
    Quests.setToggleState(true, juce::NotificationType::dontSendNotification);
    Quests.onClick = [this]() {ShowQuestsPage();};
    Home.setToggleState(true, juce::NotificationType::dontSendNotification);
    Home.onClick = [this]() {ShowHomePage();};
    My.setToggleState(true, juce::NotificationType::dontSendNotification);
    My.onClick = [this]() {ShowMyPage();};
    Tracks.setToggleState(true, juce::NotificationType::dontSendNotification);
    Tracks.onClick = [this]() {ShowTracksPage();};
    Community.setToggleState(true, juce::NotificationType::dontSendNotification);
    Community.onClick = [this]() {ShowCommunityPage();};


    //set header buttons colours
    Home.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Presets.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Bundles.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Quests.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Tracks.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Community.setColour(juce::TextButton::buttonColourId, juce::Colour(0));
    Volume.setColour(juce::TextButton::buttonColourId, juce::Colours::purple);
    My.setColour(juce::TextButton::buttonColourId, juce::Colour(0));






    addAndMakeVisible(Home);
    addAndMakeVisible(Presets);
    addAndMakeVisible(Bundles);
    addAndMakeVisible(Quests);
    addAndMakeVisible(Tracks);
    addAndMakeVisible(Community);
    addAndMakeVisible(Volume);
    addAndMakeVisible(My);

    HomePage.setVisible(true);


}

ContentComponent::~ContentComponent()
{
}

void ContentComponent::buttonClicked(juce::Button* button)
{
    if (button == &Home)
    {
        Home.setButtonText("Hello");
    }
}

void ContentComponent::ShowPresetsPage()
{

    PresetsPage.setVisible(true);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(false);
    HomePage.setVisible(false);
    MyPage.setVisible(false);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowBundlesPage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(true);
    QuestsPage.setVisible(false);
    HomePage.setVisible(false);
    MyPage.setVisible(false);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowQuestsPage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(true);
    HomePage.setVisible(false);
    MyPage.setVisible(false);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowHomePage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(false);
    HomePage.setVisible(true);
    MyPage.setVisible(false);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowMyPage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(false);
    HomePage.setVisible(false);
    MyPage.setVisible(true);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowTracksPage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(false);
    HomePage.setVisible(false);
    MyPage.setVisible(false);
    TracksPage.setVisible(true);
    CommunityPage.setVisible(false);
}
void ContentComponent::ShowCommunityPage()
{
    PresetsPage.setVisible(false);
    BundlesPage.setVisible(false);
    QuestsPage.setVisible(false);
    HomePage.setVisible(false);
    MyPage.setVisible(false);
    TracksPage.setVisible(false);
    CommunityPage.setVisible(true);
}


void ContentComponent::paint(juce::Graphics& g)
{
    // background
    g.fillAll(juce::Colour(39, 43, 46));

    // header background
    juce::Rectangle<float> Header(0, 0, getWidth(), 79);
    g.setColour(juce::Colour(69, 74, 79));
    g.drawRect(Header);
    g.fillRect(Header);



}

void ContentComponent::resized()
{
    auto area = getLocalBounds();
    auto headerFooterHeight = getHeight() - 70;
    auto temp = area.removeFromBottom(headerFooterHeight);

    Home.setBounds(60, 10, 60, 60);
    Presets.setBounds(150, 10, 80, 60);
    Bundles.setBounds(250, 10, 80, 60);
    Quests.setBounds(350, 10, 80, 60);
    Tracks.setBounds(450, 10, 80, 60);
    Community.setBounds(550, 10, 80, 60);
    My.setBounds(1400, 10, 60, 60);
    Volume.setBounds(1000, 10, 180, 60);


    PresetsPage.setBounds(temp);
    BundlesPage.setBounds(temp);
    QuestsPage.setBounds(temp);
    HomePage.setBounds(temp);
    MyPage.setBounds(temp);
    TracksPage.setBounds(temp);
    CommunityPage.setBounds(temp);

}

//==============================================================================
MainComponent::MainComponent()
{
    setSize(600, 400);

    addAndMakeVisible(view);



}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(39, 43, 46));
}


void MainComponent::resized()
{
    view.setViewedComponent(&content, false);
    view.setScrollBarsShown(true, false);

    //view.setViewPosition(0, 0); net tochno
    view.setBounds(0, 0, getWidth(), content.getWidth());

}