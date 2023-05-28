################################################################################
#                                                                               #
#   Skelly - Open Source Programming Language                                   #
#                                                                               #
#   Copyright (C) 2023 Mustafa Malik                                            #
#                                                                               #
#   This program is free software: you can redistribute it and/or modify        #
#   it under the terms of the GNU General Public License as published by        #
#   the Free Software Foundation, either version 3 of the License, or           #
#   (at your option) any later version.                                         #
#                                                                               #
#   This program is distributed in the hope that it will be useful,             #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of              #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               #
#   GNU General Public License for more details.                                #
#                                                                               #
#   You should have received a copy of the GNU General Public License           #
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.       #
#                                                                               #
################################################################################

BINARY=scc
CFLAGS=-std=c11 -DSKDEBUG -Iinclude -Wall

all: build

clean:
	rm -rf build

build: clean
	mkdir build
	gcc $(CFLAGS) compiler/scc.c compiler/test.c -o ./build/$(BINARY)

run:
	./build/$(BINARY)

bin:
	sudo cp ./build/$(BINARY) /usr/local/bin
	sudo chmod +x /usr/local/bin/$(BINARY)

.PHONY: build