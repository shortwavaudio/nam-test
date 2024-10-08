/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NeuralAmpModelerCore/NAM/dsp.h"
#include "AudioDSPTools/dsp/ImpulseResponse.h"
#include "AudioDSPTools/dsp/NoiseGate.h"
#include "AudioDSPTools/dsp/dsp.h"
#include "AudioDSPTools/dsp/wav.h"
#include "IPlugConstants.h"
#include "AudioDSPTools/dsp/ResamplingContainer/ResamplingContainer.h"
#include "ToneStack.h"
#include "ResamplingNAM.h"

//==============================================================================
/**
*/

class NamtestAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    NamtestAudioProcessor();
    ~NamtestAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NamtestAudioProcessor)
    
//    WDL_String mNAMPath;
    std::unique_ptr<ResamplingNAM> mModel;
};
