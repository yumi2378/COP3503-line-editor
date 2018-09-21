all: line-editor
line-editor: line-editor.cpp
	g++ -Wall -o line-editor line-editor.cpp line-editor.h
