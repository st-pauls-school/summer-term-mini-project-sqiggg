/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SpectrogramAudioProcessorEditor::SpectrogramAudioProcessorEditor (SpectrogramAudioProcessor& ownerProc)
    : AudioProcessorEditor(ownerProc), processor(ownerProc)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    saturationSlider.reset (new Slider (String()));
    addAndMakeVisible (saturationSlider.get());
    saturationSlider->setRange (0, 1, 0);
    saturationSlider->setSliderStyle (Slider::LinearHorizontal);
    saturationSlider->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);
    saturationSlider->setColour (Slider::backgroundColourId, Colours::white);
    saturationSlider->setColour (Slider::thumbColourId, Colours::red);
    saturationSlider->addListener (this);

    saturationSlider->setBounds (32, 48, 288, 24);

    gainSlider.reset (new Slider (String()));
    addAndMakeVisible (gainSlider.get());
    gainSlider->setRange (1, 3, 0);
    gainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::NoTextBox, true, 50, 50);
    gainSlider->setColour (Slider::thumbColourId, Colours::red);
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    gainSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    gainSlider->addListener (this);

    gainSlider->setBounds (136, 120, 75, 75);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (350, 200);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    //[/Constructor]
}

SpectrogramAudioProcessorEditor::~SpectrogramAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    saturationSlider = nullptr;
    gainSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SpectrogramAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 1, y = 45, width = 33, height = 30;
        String text (TRANS("Dry"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("04b03", 15.00f, Font::bold));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 313, y = 45, width = 33, height = 30;
        String text (TRANS("Wet"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("04b03", 15.00f, Font::bold));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 121, y = 93, width = 111, height = 35;
        String text (TRANS("GAIN"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("04b03", 45.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 41, y = 13, width = 271, height = 30;
        String text (TRANS("SATURATION"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("04b03", 45.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..

    //[/UserPaint]
}

void SpectrogramAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SpectrogramAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == saturationSlider.get())
    {
        //[UserSliderCode_saturationSlider] -- add your slider handling code here..
        *processor.saturationParameter = saturationSlider->getValue();
        //[/UserSliderCode_saturationSlider]
    }
    else if (sliderThatWasMoved == gainSlider.get())
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        *processor.gainParameter = gainSlider->getValue();
        //[/UserSliderCode_gainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SpectrogramAudioProcessorEditor::timerCallback()
{
    //if you want any display updates with a refresh timer add them here
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SpectrogramAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="SpectrogramAudioProcessor&amp; ownerProc"
                 variableInitialisers="AudioProcessorEditor(ownerProc), processor(ownerProc)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="350" initialHeight="200">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="1 45 33 30" fill="solid: ffffffff" hasStroke="0" text="Dry"
          fontname="04b03" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="313 45 33 30" fill="solid: ffffffff" hasStroke="0" text="Wet"
          fontname="04b03" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="121 93 111 35" fill="solid: ff000000" hasStroke="0" text="GAIN"
          fontname="04b03" fontsize="45.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="41 13 271 30" fill="solid: ff000000" hasStroke="0" text="SATURATION"
          fontname="04b03" fontsize="45.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="" id="6933d6ed49923557" memberName="saturationSlider" virtualName=""
          explicitFocusOrder="0" pos="32 48 288 24" bkgcol="ffffffff" thumbcol="ffff0000"
          min="0.00000000000000000000" max="1.00000000000000000000" int="0.00000000000000000000"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="0" textBoxHeight="0" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="" id="138996eab0be048b" memberName="gainSlider" virtualName=""
          explicitFocusOrder="0" pos="136 120 75 75" thumbcol="ffff0000"
          rotarysliderfill="ffffffff" rotaryslideroutline="ffffffff" min="1.00000000000000000000"
          max="3.00000000000000000000" int="0.00000000000000000000" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="50" skewFactor="1.00000000000000000000" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
