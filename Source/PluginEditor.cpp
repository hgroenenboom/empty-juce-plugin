/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cassert>

constexpr auto width = 600.0f;
constexpr auto height = 500.0f;

//==============================================================================
TestAudioProcessorEditor::TestAudioProcessorEditor (TestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setResizable(true, true);

    auto* constrainer = getConstrainer();

    // constrainer must be valid
    assert(constrainer);

    constrainer->setMinimumSize(0.5f * width, 0.5f * height);
    constrainer->setMaximumSize(2.0f * width, 2.0f * height);
    constrainer->setFixedAspectRatio(width / height);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize ((int)width, (int)height);
}

TestAudioProcessorEditor::~TestAudioProcessorEditor()
{
}

//==============================================================================
void TestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void TestAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    const auto scale = static_cast<float>(getWidth()) / width;
    //this->setTransform(juce::AffineTransform::scale(scale)); // for child components
}
