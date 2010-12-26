/*
 *
 *                This source code is part of
 *
 *                 G   R   O   M   A   C   S
 *
 *          GROningen MAchine for Chemical Simulations
 *
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2009, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 *
 * For more info, check our website at http://www.gromacs.org
 */
/*! \file
 * \brief
 * Declaration of TrajanaModule and integrally related classes.
 */
#ifndef GMX_TRAJECTORYANALYSIS_RUNNERCOMMON_H
#define GMX_TRAJECTORYANALYSIS_RUNNERCOMMON_H

#include <typedefs.h>

namespace gmx
{

class Options;
class SelectionCollection;
class TopologyInformation;
class TrajectoryAnalysisSettings;

class TrajectoryAnalysisRunnerCommon
{
    public:
        enum HelpFlag
        {
            efHelpShowOptions           = 1<<0,
            efHelpShowHidden            = 1<<1,
            efHelpShowDescriptions      = 1<<2,
        };
        //! Combination of ::HelpFlag values.
        typedef unsigned long HelpFlags;

        explicit TrajectoryAnalysisRunnerCommon(TrajectoryAnalysisSettings *settings);
        ~TrajectoryAnalysisRunnerCommon();

        Options *initOptions();
        int initOptionsDone();
        int initIndexGroups(SelectionCollection *selections);
        void doneIndexGroups(SelectionCollection *selections);
        int initTopology(SelectionCollection *selections);
        int initFirstFrame();
        bool readNextFrame();
        int initFrame();

        //! Returns flags for help printing.
        HelpFlags helpFlags() const;
        //! Returns true if input data comes from a trajectory.
        bool hasTrajectory() const;
        const TopologyInformation &topologyInformation() const;
        //! Returns the currently loaded frame.
        t_trxframe &frame() const;

    private:
        class Impl;

        Impl                *_impl;

        // Disallow copy and assign.
        TrajectoryAnalysisRunnerCommon(const TrajectoryAnalysisRunnerCommon &);
        void operator =(const TrajectoryAnalysisRunnerCommon &);
};

} // namespace gmx

#endif