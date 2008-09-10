/* the Music Player Daemon (MPD)
 * Copyright (C) 2003-2007 by Warren Dukes (warren.dukes@gmail.com)
 * This project's homepage is: http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef AUDIO_FORMAT_H
#define AUDIO_FORMAT_H

#include "mpd_types.h"

struct audio_format {
	mpd_uint32 sampleRate;
	mpd_sint8 bits;
	mpd_sint8 channels;
};

static inline void audio_format_clear(struct audio_format *af)
{
	af->sampleRate = 0;
	af->bits = 0;
	af->channels = 0;
}

static inline int audio_format_defined(const struct audio_format *af)
{
	return af->sampleRate != 0;
}

static inline int audio_format_equals(const struct audio_format *a,
				      const struct audio_format *b)
{
	return a->sampleRate == b->sampleRate &&
		a->bits == b->bits &&
		a->channels == b->channels;
}

static inline double audio_format_time_to_size(const struct audio_format *af)
{
	return af->sampleRate * af->bits * af->channels / 8.0;
}

static inline double audioFormatSizeToTime(const struct audio_format *af)
{
	return 8.0 / af->bits / af->channels / af->sampleRate;
}

#endif
