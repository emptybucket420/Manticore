//
//  support.h
//  pwner
//
//  Created by Brandon Plank on 10/1/20.
//  Copyright © 2020 GeoSn0w. All rights reserved.
//

#ifndef support_h
#define support_h

#include <stdio.h>

#define log_info 1
#define log_error 2
#define log_warning 3
#define log_i 4

/* Kernel pointer stuff */

typedef uint64_t kptr_t;
#define KPTR_NULL ((kptr_t) 0)
#define VM_MIN_KERNEL_ADDRESS 0xffffffe000000000ULL
#define VM_MAX_KERNEL_ADDRESS 0xfffffff3ffffffffULL
#define KERN_POINTER_VALID(val) (((val) & 0xffffffff) != 0xdeadbeef && (val) >= VM_MIN_KERNEL_ADDRESS && (val) <= VM_MAX_KERNEL_ADDRESS)

#define TF_PLATFORM 0x00000400 /* task is a platform binary */

#define SafeFree(x) do { if (x) free(x); } while(false)
#define SafeFreeNULL(x) do { SafeFree(x); (x) = NULL; } while(false)

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
#define fileExists(file) [[NSFileManager defaultManager] fileExistsAtPath:@(file)]

void Log(int type,const char *format, ...) __attribute__ ((format (printf, 2, 3)));
NSString *programVersion(void);


/* Property List Support functions */
bool modifyPlist(NSString *filename, void (^function)(id));
NSDictionary *readPlist(NSString *filename);

// TODO
bool createEmptyPlist(NSString *path);

#endif /* support_h */