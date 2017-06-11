/**
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/**
*/
class JuceDelayAudioProcessor  : public AudioProcessor
{

public:

  JuceDelayAudioProcessor();
  ~JuceDelayAudioProcessor();

  /**
   * Pre-playback initialization of the delay processor.
   *
   * \param[in] double  Audio sample rate.
   * \param[in] double  Number of audio samples per processing block.
   */
  void prepareToPlay (double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

  #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
  #endif

  void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

  AudioProcessorEditor* createEditor() override;
  bool hasEditor() const override;

  const String getName() const override;

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  double getTailLengthSeconds() const override;

  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram (int index) override;
  const String getProgramName (int index) override;
  void changeProgramName (int index, const String& newName) override;

  void getStateInformation (MemoryBlock& destData) override;
  void setStateInformation (const void* data, int sizeInBytes) override;

  void setDelay(float delay) { m_delay = delay; }

private:

  float m_delay; /// \todo Making this public temporarily.

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceDelayAudioProcessor)
};
