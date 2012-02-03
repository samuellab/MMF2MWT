MMF2MWT allows command line processing of MMF compressed video files using Rex Kerr's Multi Worm Tracker.

The code for the command line program and the command line program (mmf2mwt.exe) are found in the MWTMMF directory.  mmmf2mwt.exe can be called with several options:

mmf2mwt.exe pathToImageStack\imagestackname.mmf will use default settings and produce output as 

pathToImageStack\TODAYSDATEANDTIME\imagestackname_NNNNNk.blobs
pathToImageStack\TODAYSDATEANDTIME\imagestackname.summary

default settings can be adjusted by editing the file
defaultMWTSettings.txt, which is produced when the program is run for the first time

other options can be found by running mmf2mwt with no arguments

-----
explanation of settings:
these are the default settings, with explanation


frame_rate: 30 
	mmf was recorded at 30 frames per second

thresholdToFillObject: 50 
	blobs are filled out to this threshold level (gray levels above background) 

thresholdToMarkObject: 70
	blobs must contain pixels above thresholdToMarkObject to be marked 

minObjectArea: 10
minNewObjectArea: 30
maxNewObjectArea: 20000
maxObjectArea: 30000

	new blobs must be between 30 and 20,000 pixels in area.  To avoid dissapearing, a blob must maintain its area between 10 and 30,000 pixels

startFrame: 0
endFrame: -1

	mmf frame to start analysis (default 0: )
     mmf frame to end analysis (if <0, process all frames)

adpatationAlpha: 8
dancerBorderSize: 10
minFramesObjectMustPersist: 60
updateBandNumber: 16

	mwt settings you will probably not need to adjust.  
	each frame contributes 2^(-adaptationAlpha) towards updating the background.  
	ask Rex about dancerBorderSize.  
	we don't write out objects that lasted less than minFramesObjectMustPersist.  
	ask Rex about updateBandNumber

windowOutputUpdateInterval: -1
writeLog: false

	If windowOutputUpdateInterval > 0, we show a window with the current state of the MWT every windowOutputUpdateInterval frames.  The red and green channels are the original image from the MMF; the blue channel is the output of the MWT showObjects function.  Untracked objects will appear yellow.  This operation takes about 5 times as long as all the other operations put together, so set windowOutputUpdate to a larger number (e.g. 30) if you plan to use it.

	if writeLog is true, we dump some text output containing diagnostic information to outputpath/outputprefix.mwtlog
otherwise, we dump it to cout

------
getting the code
This code comes as a git module with submodules.  One of the submodules also has a submodule.  

To get all of the code, using the git shell:

git clone git@github.com:samuellab/MMF2MWT.git
git submodule init
git submodule update
cd Image-Stack-Compressor
git submodule init
git submodule update

This code has a netbeans project (in MWTMMF/nbroject) configured for Windows32 and mingw.  Netbeans and help installing it for your platform are available from netbeans.org

The file mwt2mmf.exe is a compiled windows command line program, which should work on any modern windows system.

-----
LICENSE


MWT COMMAND LINE PROCESSOR FOR MMF FILES

Code Copywright by Other Authors:

MWT (ALL FILES IN DLL FOLDER) 
Copyright (C) 2007 - 2010 Howard Hughes Medical Institute
Copyright (C) 2007 - 2010 Rex A. Kerr, Nicholas A. Swierczek
distributed under the terms of the GNU Lesser General Public Licence version 2.1 (LGPL 2.1). For details, see GPL2.txt and LGPL2.1.txt, or http://www.gnu.org/licences 
To contact the authors, email kerrlab@users.sourceforge.net.

OpenCV (in submodule Image-Stack-Compressor)
http://opencv.willowgarage.com/wiki/
distributed under BSD license

yaml-cpp (in submodule yaml-cpp)
by Jesse Beder
http://code.google.com/p/yaml-cpp/
distributed under the MIT license


Unless otherwise noted, all other code is (C) Marc Gershow; licensed under the Creative Commons Attribution Share Alike 3.0 United States License.
To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to
Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
Any modification or redistribution of this work must include this license.


*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**The author is under no obligation to provide any services by way of maintenance, updates or corrections for this software.  Nor is the author obligated to provide technical support or any form of assistance using this software.

Note that the creative commons license contains additional disclaimers and limitations on liability.

*from the BSD 3.0 license
** adapted from Albrecht and Bargmann, Nature Methods 8,599–605 (2011) doi:10.1038/nmeth.1630