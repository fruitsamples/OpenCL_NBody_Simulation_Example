//
// File:       hud.h
//
// Abstract:   This example performs an NBody simulation which calculates a gravity field 
//             and corresponding velocity and acceleration contributions accumulated 
//             by each body in the system from every other body.  This example
//             also shows how to mitigate computation between all available devices
//             including CPU and GPU devices, as well as a hybrid combination of both,
//             using separate threads for each simulator.
//
// Version:    <1.0>
//
// Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple Inc. ("Apple")
//             in consideration of your agreement to the following terms, and your use,
//             installation, modification or redistribution of this Apple software
//             constitutes acceptance of these terms.  If you do not agree with these
//             terms, please do not use, install, modify or redistribute this Apple
//             software.
//
//             In consideration of your agreement to abide by the following terms, and
//             subject to these terms, Apple grants you a personal, non - exclusive
//             license, under Apple's copyrights in this original Apple software ( the
//             "Apple Software" ), to use, reproduce, modify and redistribute the Apple
//             Software, with or without modifications, in source and / or binary forms;
//             provided that if you redistribute the Apple Software in its entirety and
//             without modifications, you must retain this notice and the following text
//             and disclaimers in all such redistributions of the Apple Software. Neither
//             the name, trademarks, service marks or logos of Apple Inc. may be used to
//             endorse or promote products derived from the Apple Software without specific
//             prior written permission from Apple.  Except as expressly stated in this
//             notice, no other rights or licenses, express or implied, are granted by
//             Apple herein, including but not limited to any patent rights that may be
//             infringed by your derivative works or by other works in which the Apple
//             Software may be incorporated.
//
//             The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
//             WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
//             WARRANTIES OF NON - INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
//             PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION
//             ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
//
//             IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
//             CONSEQUENTIAL DAMAGES ( INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//             SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//             INTERRUPTION ) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION
//             AND / OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER
//             UNDER THEORY OF CONTRACT, TORT ( INCLUDING NEGLIGENCE ), STRICT LIABILITY OR
//             OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright ( C ) 2008 Apple Inc. All Rights Reserved.
//

////////////////////////////////////////////////////////////////////////////////

#ifndef __HUD_H__
#define __HUD_H__

#include <cstddef>

class StuffPerSecondMeter
{
public:
    StuffPerSecondMeter(size_t frameBufferSize, bool rampUp);
    virtual ~StuffPerSecondMeter();

    void reset();
    void recordFrame(double stuff, double dt);

    double stuffPerSecond() const;

private:
    size_t  _frameBufferSize;
    double *_frameBuffer;
    size_t  _i;
    bool    _rampUp;
    size_t  _n;
};

class SmoothMeter
{
public:
    SmoothMeter(unsigned w, unsigned h, unsigned max, const char *legendText);
    virtual ~SmoothMeter();

    void reset();
    void setTargetValue(double target);

    void update();
    void draw();

    unsigned max() const
    {
        return _max;
    }
    double value() const
    {
        return _value;
    }
    double smoothValue() const
    {
        return _smoothValue;
    }

private:
    unsigned _w;
    unsigned _h;
    unsigned _max;
    double   _value;
    double   _smoothValue;
    unsigned _backgroundTexture;
    unsigned _needleTexture;
    unsigned _legendTexture;
    const char *_legend;
};

class Button
{
public:
    Button(float x, float y, float w, float h);
    virtual ~Button();

    bool contains(float x, float y) const;

    float x() const
    {
        return _x;
    }
    float y() const
    {
        return _y;
    }
    float w() const
    {
        return _w;
    }
    float h() const
    {
        return _h;
    }

private:
    float _x, _y, _w, _h;
};

enum TrackingState
{
    NOTHING,
    PRESSED,
    UNPRESSED,
};

TrackingState TrackButton(Button const *button, float x, float y, TrackingState previous);
void DrawButton(Button const *button);
void InitButton(unsigned w, unsigned h);

#endif
