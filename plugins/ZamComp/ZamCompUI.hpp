/*
 * Wobble Juice Plugin
 * Copyright (C) 2014 Andre Sklenar <andre.sklenar@gmail.com>, www.juicelab.cz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the doc/GPL.txt file.
 */

#ifndef WOBBLEJUICEUI_HPP_INCLUDED
#define WOBBLEJUICEUI_HPP_INCLUDED

#include "DistrhoUI.hpp"

#include "ImageKnob.hpp"

#include "ZamCompArtwork.hpp"
#include "ZamCompPlugin.hpp"

using DGL::Image;
using DGL::ImageKnob;

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class ZamCompUI : public UI,
                      public ImageKnob::Callback
{
public:
    ZamCompUI();
    ~ZamCompUI() override;

protected:
    // -------------------------------------------------------------------
    // Information

    unsigned int d_getWidth() const noexcept override
    {
        return ZamCompArtwork::zamcompWidth;
    }

    unsigned int d_getHeight() const noexcept override
    {
        return ZamCompArtwork::zamcompHeight;
    }

    // -------------------------------------------------------------------
    // DSP Callbacks

    void d_parameterChanged(uint32_t index, float value) ;
    void d_programChanged(uint32_t index) ;

    // -------------------------------------------------------------------
    // Widget Callbacks

    void imageKnobDragStarted(ImageKnob* knob) override;
    void imageKnobDragFinished(ImageKnob* knob) override;
    void imageKnobValueChanged(ImageKnob* knob, float value) override;

    void onDisplay() override;

private:
    Image fImgBackground;
    ImageKnob* fKnobAttack;
    ImageKnob* fKnobRelease;
    ImageKnob* fKnobThresh;
    ImageKnob* fKnobRatio;
    ImageKnob* fKnobKnee;
    ImageKnob* fKnobMakeup;
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // WOBBLEJUICEUI_HPP_INCLUDED