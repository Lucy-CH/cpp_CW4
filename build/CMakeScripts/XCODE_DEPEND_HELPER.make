# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.SDL2_App.Debug:
/Users/lecheng/Desktop/CPPCoursework2020-v101/build/Debug/SDL2_App:\
	/usr/local/lib/libSDL2main.a\
	/usr/local/lib/libSDL2.dylib\
	/usr/local/lib/libSDL2_ttf.dylib\
	/usr/local/lib/libSDL2_image.dylib
	/bin/rm -f /Users/lecheng/Desktop/CPPCoursework2020-v101/build/Debug/SDL2_App


PostBuild.SDL2_App.Release:
/Users/lecheng/Desktop/CPPCoursework2020-v101/build/Release/SDL2_App:\
	/usr/local/lib/libSDL2main.a\
	/usr/local/lib/libSDL2.dylib\
	/usr/local/lib/libSDL2_ttf.dylib\
	/usr/local/lib/libSDL2_image.dylib
	/bin/rm -f /Users/lecheng/Desktop/CPPCoursework2020-v101/build/Release/SDL2_App


PostBuild.SDL2_App.MinSizeRel:
/Users/lecheng/Desktop/CPPCoursework2020-v101/build/MinSizeRel/SDL2_App:\
	/usr/local/lib/libSDL2main.a\
	/usr/local/lib/libSDL2.dylib\
	/usr/local/lib/libSDL2_ttf.dylib\
	/usr/local/lib/libSDL2_image.dylib
	/bin/rm -f /Users/lecheng/Desktop/CPPCoursework2020-v101/build/MinSizeRel/SDL2_App


PostBuild.SDL2_App.RelWithDebInfo:
/Users/lecheng/Desktop/CPPCoursework2020-v101/build/RelWithDebInfo/SDL2_App:\
	/usr/local/lib/libSDL2main.a\
	/usr/local/lib/libSDL2.dylib\
	/usr/local/lib/libSDL2_ttf.dylib\
	/usr/local/lib/libSDL2_image.dylib
	/bin/rm -f /Users/lecheng/Desktop/CPPCoursework2020-v101/build/RelWithDebInfo/SDL2_App




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libSDL2.dylib:
/usr/local/lib/libSDL2_image.dylib:
/usr/local/lib/libSDL2_ttf.dylib:
/usr/local/lib/libSDL2main.a:
