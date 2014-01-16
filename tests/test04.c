/* ctry - exception system for C language.
 * Copyright (C) 2013 Samuel Rodriguez Sevilla <laparca {at} laparca.es>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ctry.h>
#include <stdio.h>

#define ERR_01   1
#define ERR_02   2
#define ERR_03   4

int main(void) {
	int ret = ERR_01 | ERR_02 | ERR_03;
	int i;
	for(i = 1; i <= 3; i ++) {
		CTRY {
			printf("Throwing error inside CTRY body...");
			CTHROW(i);
		}
		CCATCH(1) {
			printf("Error 1 catched\n");
			ret &= ~ERR_01;
		}
		CCATCH(2) {
			printf("Error 2 catched\n");
			ret &= ~ERR_02;
		}
		CCATCH(3) {
			printf("Error 3 catched\n");
			ret &= ~ERR_03;
		}
		CCATCH(4) {
			printf("Error 4 catched. This is an error!\n");
			ret = 4;
			goto stop;
		}
		CENDTRY;
	}

stop:
	return ret;
}

// vim:ts=4:sw=4:cindent

