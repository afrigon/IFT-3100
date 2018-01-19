TARGET = app.o
TARGETDIR = build
SOURCE = main.cpp
SOURCEDIR = src


DEV = g++ -std=c++11 -g -Wc++11-narrowing -Wall -Wextra -pedantic
PROD = g++ -std=c++11 -03
LINT = ./lint.py

default: osx

win:
	$(LINT) $(SOURCEDIR)\\*
	$(DEV) -o $(TARGETDIR)\\win\\$(TARGET) $(SOURCEDIR)\\$(SOURCE)

osx:
	$(LINT) $(SOURCEDIR)/*
	$(DEV) -lglfw -o $(TARGETDIR)/osx/$(TARGET) $(SOURCEDIR)/$(SOURCE)

linux:
	$(LINT) $(SOURCEDIR)/*
	$(DEV) -o $(TARGETDIR)/linux/$(TARGET) $(SOURCEDIR)/$(SOURCE)


win-prod:
	$(LINT) $(SOURCEDIR)\\*
	$(PROD) -o $(TARGETDIR)\\win\\$(TARGET) $(SOURCEDIR)\\$(SOURCE)

osx-prod:
	$(LINT) $(SOURCEDIR)/*
	$(PROD) -lglfw -o $(TARGETDIR)/osx/$(TARGET) $(SOURCEDIR)/$(SOURCE)

linux-prod:
	$(LINT) $(SOURCEDIR)/*
	$(PROD) -o $(TARGETDIR)/linux/$(TARGET) $(SOURCEDIR)/$(SOURCE)
