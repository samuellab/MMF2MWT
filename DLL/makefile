SHELL=/bin/bash
CC = g++
FLAGS = -Wall -O2 -fno-strict-aliasing -ggdb3 -shared
UNIT = -DUNIT_TEST_OWNER
OS = -DWINDOWS 
OUTDIR = c:/MWT/lib
all: unit_geometry unit_lists unit_storage unit_image unit_blob unit_model unit_library

unit_geometry: makefile MWT_Geometry.h MWT_Geometry.cc
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_geometry MWT_Geometry.cc

MWT_Geometry.o: makefile MWT_Geometry.h MWT_Geometry.cc
	$(CC) $(FLAGS) $(OS) -o MWT_Geometry.o MWT_Geometry.cc
	
unit_lists: makefile MWT_Lists.h MWT_Lists.cc MWT_Geometry.h
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_lists MWT_Lists.cc

MWT_Lists.o: makefile MWT_Lists.h MWT_Lists.cc MWT_Geometry.h
	$(CC) $(FLAGS) $(OS) -o MWT_Lists.o MWT_Lists.cc
	
unit_storage: makefile MWT_Storage.h MWT_Storage.cc MWT_Lists.h
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_storage MWT_Storage.cc

MWT_Storage.o: makefile MWT_Storage.h MWT_Storage.cc MWT_Lists.h
	$(CC) $(FLAGS) $(OS) -o MWT_Storage.o MWT_Storage.cc
	
MWT_Image.o: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.cc
	$(CC) $(FLAGS) $(OS) -c -o MWT_Image.o MWT_Image.cc

unit_image: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.cc
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_image MWT_Image.cc

MWT_Blob.o: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Blob.h MWT_Blob.cc
	$(CC) $(FLAGS) $(OS) -c -o MWT_Blob.o MWT_Blob.cc

unit_blob: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.o MWT_Blob.h MWT_Blob.cc
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_blob MWT_Blob.cc MWT_Image.o
	
MWT_Model.o: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.o MWT_Model.h MWT_Model.cc
	$(CC) $(FLAGS) $(OS) -c -o MWT_Model.o MWT_Model.cc
	
unit_model: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.o MWT_Model.h MWT_Model.cc
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_model MWT_Model.cc MWT_Image.o
	
unit_library: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.o MWT_Blob.h MWT_Blob.o MWT_Model.h MWT_Model.o MWT_Library.h MWT_Library.cc
	$(CC) $(FLAGS) $(UNIT) $(OS) -o unit_library MWT_Library.cc MWT_Image.o MWT_Blob.o MWT_Model.o
	#valgrind --leak-check=full --error-exitcode=2 ./unit_library -quiet

MWT_Library.o: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Blob.h MWT_Model.h MWT_Library.h MWT_Library.cc
	$(CC) $(FLAGS) $(OS) -c -o MWT_Library.o MWT_Library.cc 
  
DLL: makefile MWT_Storage.h MWT_Geometry.h MWT_Lists.h MWT_Image.h MWT_Image.o MWT_Blob.h MWT_Blob.o MWT_Model.h MWT_Model.o MWT_Library.h MWT_Library.o MWT_DLL.h MWT_DLL.cc
	$(CC) $(FLAGS) $(OS) -o $(OUTDIR)/MWT.dll MWT_DLL.cc MWT_Image.o MWT_Blob.o MWT_Model.o MWT_Library.o

clean:
	rm unit_geometry unit_lists unit_storage unit_image unit_blob unit_model unit_library
	rm test_image.tiff performance_imprint.tiff worm_imprint.tiff worm_noisy.tiff
	rm -r 20071212_130514

