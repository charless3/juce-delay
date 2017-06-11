/**
 *
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

JuceDelayAudioProcessorEditor::JuceDelayAudioProcessorEditor (JuceDelayAudioProcessor& p)
  : AudioProcessorEditor (&p),
    m_processor (p),
    m_delayKnob ("Delay Knob"),
    m_delayLabel()
{
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize (800, 600);

  //m_delayKnob.setExplicitFocusOrder(3);
  m_delayKnob.setRange (10e-3, 2.5, 1e-3);
  m_delayKnob.setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
  m_delayKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 90, 20);
  m_delayKnob.setTextValueSuffix (" sec"); /// \todo Might be better to change to ms.
  m_delayKnob.addListener (this);
  addAndMakeVisible (m_delayKnob);

  m_delayLabel.setText ("Delay", dontSendNotification);
  m_delayLabel.setJustificationType (Justification::centredBottom);
  m_delayLabel.setFont (15.0f);
  m_delayLabel.attachToComponent (&m_delayKnob, false);
  addAndMakeVisible (m_delayLabel);
}

JuceDelayAudioProcessorEditor::~JuceDelayAudioProcessorEditor()
{
}

void JuceDelayAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
  // if (slider == &m_delayKnob) {
  //   m_processor.setDelay (m_delayKnob.getValue()); /// \todo Might need to use setValueNotifyingHost instead.
  // }
}

void JuceDelayAudioProcessorEditor::paint (Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll (getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

  g.setColour (Colours::white);
  g.setFont (15.0f);
}

void JuceDelayAudioProcessorEditor::resized()
{
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  m_delayKnob.setBounds (proportionOfWidth(0.03f), proportionOfHeight(0.08f),
    proportionOfWidth(0.20f), proportionOfHeight(0.20f));
}
