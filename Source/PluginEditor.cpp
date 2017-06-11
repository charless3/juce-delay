/**
 *
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

JuceDelayAudioProcessorEditor::JuceDelayAudioProcessorEditor (JuceDelayAudioProcessor& p)
  : AudioProcessorEditor (&p),
    m_processor (p),
    m_delayKnob ("Delay Knob"),
    m_feedbackKnob ("Feedback Knob"),
    m_mixKnob ("Mix Knob"),
    m_delayLabel(),
    m_feedbackLabel(),
    m_mixLabel()
{
  // Set window size.
  setSize (400, 300);
  setResizable (true, true); /// \todo This isn't working.

  // Set up delay time control.
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

  // Set up feedback control.
  m_feedbackKnob.setRange (0.0, 1.15, 1e-2); /// \todo Adjust the step size if needed. Choosing 1.15 for unstable oscillations.
  m_feedbackKnob.setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
  m_feedbackKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 90, 20);
  m_feedbackKnob.addListener (this);
  addAndMakeVisible (m_feedbackKnob);
  m_feedbackLabel.setText ("Feedback", dontSendNotification);
  m_feedbackLabel.setJustificationType (Justification::centredBottom);
  m_feedbackLabel.setFont (15.0f);
  m_feedbackLabel.attachToComponent (&m_feedbackKnob, false);
  addAndMakeVisible (m_feedbackLabel);

  // Set up mix control.
  m_mixKnob.setRange (0.0, 1.0, 1e-2);
  m_mixKnob.setValue (0.5, dontSendNotification);
  m_mixKnob.setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
  m_mixKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 90, 20);
  m_mixKnob.addListener (this);
  addAndMakeVisible (m_mixKnob);
  m_mixLabel.setText ("Mix", dontSendNotification);
  m_mixLabel.setJustificationType (Justification::centredBottom);
  m_mixLabel.setFont (15.0f);
  m_mixLabel.attachToComponent (&m_mixKnob, false);
  addAndMakeVisible (m_mixLabel);
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
  m_delayKnob.setBounds (proportionOfWidth(0.1f), proportionOfHeight(0.1f),
    proportionOfWidth(0.20f), proportionOfHeight(0.30f));
  m_feedbackKnob.setBounds (proportionOfWidth(0.4f), proportionOfHeight(0.1f),
    proportionOfWidth(0.20f), proportionOfHeight(0.30f));
  m_mixKnob.setBounds (proportionOfWidth(0.70f), proportionOfHeight(0.1f),
    proportionOfWidth(0.20f), proportionOfHeight(0.30f));
}
