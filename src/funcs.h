/**
 * @file   funcs.h
 * @copyright (c) 2015 Ahmad Fatoum. Code available under terms of the GNU General Public License 3.0
 * @brief  contains declarations for ev3 commands
 *
 * All commands take FILE* loc arguments for loc files
 * and UTF-8 encoded rem file names, if any.
 * On POSIX, this needs no changes. On Windows, for multibyte input
 * UCS-2 to UTF-8 conversion would need to be handled by caller
 * @see branch win32-unicode for a possible way to implement \p main.
 *      All calls to these functions should be in main.c
 * @author Ahmad Fatoum
 * @warning unless otherwise stated, passing \p NULL to a function is undefined behavior.
 */
#ifndef EV3DUDER_FUNCS_H
#define EV3DUDER_FUNCS_H

#include <stdio.h>
#include <stddef.h>
/**
 * @name    General Usage
 * @ingroup EV3 commands
 *
 * @param [in] loc Local FILE*s
 * @param [in] rem Remote EV3 UTF-8 encoded path strings
 *
 * @retval error according to enum #ERR
 */

//! upload local file \p loc to remote destination \p rem
extern int up(FILE *loc, const char *rem);

//! download remote source \p rem to local file \p loc
extern int dl(const char *rem, FILE *loc);

//! print connection information, beep and exit
extern int info(const char *arg);

//! run remote .rbf file \p rem via VM
extern int run(const char *rem, unsigned timeout);

//! list contents of remote directory \p rem
extern int ls(const char *rem);


//! remove remote file or directory \p rem
extern int rm(const char *rem);

//! create directory \p rem on remote system
extern int mkdir_(const char *rem);

//! fill \p *buf with a rbf file executing \p cmd
extern size_t mkrbf(char **buf, const char *cmd);

//! execute direct command
extern int vmexec(FILE *in, FILE *out, int locals, int globals, int use_reply);

//! close given ev3 file handle range
extern int closehnd(int start, int end);

//! tunnel stdio to established ev3 connection
extern int tunnel_mode();

extern int listen_mode();

extern int bridge_mode();

//! reboot from Linux to bootloader eeprom
extern int bootloader_enter(void);

//! install new firmware to the brick
extern int bootloader_install(FILE *fp);

//! print brick hardware version
extern int bootloader_info(void);

//! exit from bootloader eeprom
extern int bootloader_exit(void);

extern u32 crc32(u32 crc, const void *buf, size_t size);

//! Pack files into a UF2 archive
extern int uf2_pack(FILE *fp, const char *brickdir, const char **file_array, int files);

//! Unpack files from a UF2 archive
extern int uf2_unpack(FILE *fp, const char *dstdir, int use_paths);

#if 0 // not yet implemented
//! concatenate contents of \p count of \p rem FILEs to the EV3's LCD
extern int cat(const char *rem, size_t count);
#endif

#endif
