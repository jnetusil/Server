/*
* copyright (c) 2010 Sveriges Television AB <info@casparcg.com>
*
*  This file is part of CasparCG.
*
*    CasparCG is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    CasparCG is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with CasparCG.  If not, see <http://www.gnu.org/licenses/>.
*
*/
#pragma once

#include "../util.h"

#include <core/mixer/audio/audio_mixer.h>

#include <common/memory/safe_ptr.h>

#include <boost/noncopyable.hpp>

#include <agents.h>
#include <vector>

struct AVPacket;
struct AVFormatContext;

namespace caspar {

namespace core {

struct video_format_desc;

}

namespace ffmpeg {

class audio_decoder : boost::noncopyable
{
public:

	typedef Concurrency::ISource<safe_ptr<AVPacket>>& source_t;
	typedef Concurrency::ITarget<safe_ptr<core::audio_buffer>>& target_t;
	
	explicit audio_decoder(source_t& source, target_t& target, AVFormatContext& context, const core::video_format_desc& format_desc);
	
	int64_t nb_frames() const;

private:
	
	struct implementation;
	safe_ptr<implementation> impl_;
};

}}