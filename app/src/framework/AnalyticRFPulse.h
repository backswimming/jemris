/** @file AnalyticRFPulse.h
 *  @brief Implementation of JEMRIS AnalyticRFPulse
 */

/*
 *  JEMRIS Copyright (C) 2007-2008  Tony Stöcker, Kaveh Vahedipour
 *                                  Forschungszentrum Jülich, Germany
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ANALYTICRFPULSE_H_
#define ANALYTICRFPULSE_H_

#include "RFPulse.h"

/**
 * @brief Analytic RF pulse
 */

class AnalyticRFPulse : public RFPulse {

 public:

    /**
     * @brief Default constructor
     */
    AnalyticRFPulse() {};

    /**
     * @brief Copy constructor.
     */
    AnalyticRFPulse  (const AnalyticRFPulse&);

    /**
     * @brief Default destructor.
     */
    ~AnalyticRFPulse () {};

    /**
     *  See Module::clone
     */
    inline AnalyticRFPulse* Clone() const {return (new AnalyticRFPulse(*this));};

     /**
     * @brief Prepare the hard RF pulse.
     *
     * @param  mode Sets the preparation mode, one of enum PrepareMode {PREP_INIT,PREP_VERBOSE,PREP_UPDATE}.
     * @return      Success.
     */
    virtual bool Prepare  (PrepareMode mode);

    /**
     * @brief Get Magnitude
     *
     * @param  time The flip angle as double.
     * @return the Magnitude.
     */
    virtual double GetMagnitude  (double time);

    /**
     * @brief Get phase
     *
     * @param  mod  Module.
     * @param  time Time.
     * @return Phase.
     */
    inline static double getAnalyticPhase (Module* mod, double time) {return (((AnalyticRFPulse*) mod)->m_analytic_phase*180.0/PI);};


 protected:

    /**
     * Get informations
     *
     * @return Infos for display.
     */
    virtual string          GetInfo        ();

    double m_analytic_phase;    /**< @brief Phase */
};

#endif /*ANALYTICRFPULSE_H_*/
