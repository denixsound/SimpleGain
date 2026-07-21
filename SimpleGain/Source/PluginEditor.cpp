/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGainAudioProcessorEditor::SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    volumeSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    volumeSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible (volumeSlider);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setValue(audioProcessor.rawVolume);
    volumeSlider.onValueChange = [this] {
        audioProcessor.rawVolume = volumeSlider.getValue();
    };
    setSize (400, 300);
}

SimpleGainAudioProcessorEditor::~SimpleGainAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleGainAudioProcessorEditor::resized()
{
    volumeSlider.setBounds(100, 50, 200, 200);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
