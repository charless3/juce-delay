/**
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

/**
 *
 */
class JuceDelayAudioProcessorEditor : public AudioProcessorEditor
{
public:
  JuceDelayAudioProcessorEditor (JuceDelayAudioProcessor&);
  ~JuceDelayAudioProcessorEditor();

  void paint (Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to access the
  // processor object that created it.
  JuceDelayAudioProcessor& processor;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceDelayAudioProcessorEditor)
};
