/**
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

using GLib;
using FsoFramework;

const string ORIGINAL_CONTENT = "Dieser Satz kein Verb!";
const string OVERLAY_CONTENT = "This is the overlay content...";

//===========================================================================
void test_overlay()
//===========================================================================
{
    {
        var overlay = new OverlayFile( "./overlayfile.txt", OVERLAY_CONTENT );
        var original = FileHandling.read( "./overlayfile.txt.saved" );
        assert( original == ORIGINAL_CONTENT );
        var contents = FileHandling.read( "./overlayfile.txt" );
        assert( contents == OVERLAY_CONTENT );
    }
    var contents = FileHandling.read( "./overlayfile.txt" );
    assert( contents == ORIGINAL_CONTENT );
    assert( !FileHandling.isPresent( "./overlayfile.txt.saved" ) );
}

//===========================================================================
void main( string[] args )
//===========================================================================
{
    Test.init( ref args );

    // Test.add_func( "/Overlay", test_overlay );

    Test.run();
}

// vim:ts=4:sw=4:expandtab
