/**
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

/**
 *
 */
class JuceDelayAudioProcessorEditor : public AudioProcessorEditor,
                                      public Slider::Listener
{

public:

  JuceDelayAudioProcessorEditor (JuceDelayAudioProcessor&);
  ~JuceDelayAudioProcessorEditor();

  void sliderValueChanged(Slider* slider);

  void paint (Graphics&) override;
  void resized() override;

private:

  JuceDelayAudioProcessor& m_processor;

  Slider m_delayKnob;
  Slider m_feedbackKnob;
  Slider m_mixKnob;
  Label m_delayLabel;
  Label m_feedbackLabel;
  Label m_mixLabel;
  /// \todo Other parameters: feedback, mix, maybe rate/depth for LFO modulation, any others?
  ///       Any others? Might want to make this a stereo delay with separate delay times for each channel.
  ///       I've seen some effects pedals that break the second delay into note divisions (eigth, quarter, etc).

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceDelayAudioProcessorEditor)

};
