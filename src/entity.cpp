/* {{{
	MIT LICENSE

	Copyright (c) 2018, Mihail Szabolcs

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the 'Software'), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
}}} */
#include "entity.h"

namespace od {

Entity::Entity(void)
{
	// nop
}

void Entity::set(const QString &key, const QString &value)
{
	mProperties[key] = value;
}

void Entity::addBrush(const Brush &brush)
{
	mBrushes.append(brush);
}

void Entity::serialize(QTextStream &stream, const float scale) const
{
	stream << "{\n";

	for(const QString &key : mProperties.keys())
		stream << "\t\"" << key << "\"" << " " << "\"" << mProperties.value(key) << "\"\n";

	for(const Brush &brush : mBrushes)
		brush.serialize(stream, scale);

	stream << "}\n";
}

/* od */ }

/* vim: set ts=4 sw=4 sts=4 noet: */
