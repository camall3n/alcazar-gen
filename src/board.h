/*******************************************************************************
* alcazar-gen
*
* Copyright (c) 2015 Florian Pigorsch
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*******************************************************************************/

#pragma once

#include <iostream>
#include <set>
#include <tuple>
#include "coordinates.h"
#include "path.h"
#include "wall.h"


class Board
{
    public:
        Board() = default;
        Board(int w, int h);
        
        const int& width() const { return m_width; }
        const int& height() const { return m_height; }
        int index(int x, int y) const { return x + m_width * y; }
        int index(const Coordinates& c) const { return index(c.x(), c.y()); }
        Coordinates coord(int index) const { return Coordinates(index % m_width, index / m_width); }
        
        std::tuple<bool, bool, Path> solve() const;
        
        void addWall(const Wall& w) { m_walls.insert(w); }
        bool hasWall(const Wall& w) const { return m_walls.find(w) != m_walls.end(); }
        
        void print(std::ostream& os, const Path& path) const;
    
    private:
        int m_width = 0;
        int m_height = 0;
        
        std::set<Wall> m_walls;
};

std::ostream& operator<<(std::ostream& os, const Board& board);
