/* 
 * PiTiVi
 * Copyright (C) <2004> Edward G. Hervey <hervey_e@epita.fr>
 *                      Guillaume Casanova <casano_g@epita.fr>
 *
 * This software has been written in EPITECH <http://www.epitech.net>
 * EPITECH is a computer science school in Paris - FRANCE -
 * under the direction of Flavien Astraud and Jerome Landrieu.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef PITIVI_TIMELINEBIN_H
#define PITIVI_TIMELINEBIN_H

/*
 * Potentially, include other headers on which this header depends.
 */

#include <gnl/gnl.h>
#include "pitivi-globalbin.h"
#include "pitivi-types.h"

/*
 * Type macros.
 */

#define PITIVI_TIMELINEBIN_TYPE (pitivi_timelinebin_get_type ())
#define PITIVI_TIMELINEBIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PITIVI_TIMELINEBIN_TYPE, PitiviTimelineBin))
#define PITIVI_TIMELINEBIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PITIVI_TIMELINEBIN_TYPE, PitiviTimelineBinClass))
#define PITIVI_IS_TIMELINEBIN(obj) (G_TYPE_CHECK_TYPE ((obj), PITIVI_TIMELINEBIN_TYPE))
#define PITIVI_IS_TIMELINEBIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PITIVI_TIMELINEBIN_TYPE))
#define PITIVI_TIMELINEBIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PITIVI_TIMELINEBIN_TYPE, PitiviTimelineBinClass))

typedef struct _PitiviTimelineBinPrivate PitiviTimelineBinPrivate;

struct _PitiviTimelineBin
{
  PitiviGlobalBin parent;

  /* instance public members */
  GnlTimeline	*timeline;

  /* private */
  PitiviTimelineBinPrivate *private;
};

struct _PitiviTimelineBinClass
{
  PitiviGlobalBinClass parent;
  /* class members */
};

/* used by PITIVI_TIMELINEBIN_TYPE */
GType pitivi_timelinebin_get_type (void);

/*
 * Method definitions.
 */

PitiviTimelineBin	*pitivi_timelinebin_new(GnlTimeline	*timeline,
						GnlGroup	*audiogroup,
						GnlGroup	*videogroup,
						PitiviProjectSettings *psettings);

void			pitivi_timelinebin_set_output_file(PitiviTimelineBin *bin, gchar *filename);

#endif