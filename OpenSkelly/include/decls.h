//
//  decls.h
//  OpenSkelly
//
//  Created by Mustafa Malik on 18/12/2023.
//

#ifndef __DECLS_H__
#define __DECLS_H__

#ifdef __cplusplus
#   define SK_EXPORT
#   define SK_EXPORT_ALL    inline
#else
#   define SK_EXPORT        extern
#   define SK_EXPORT_ALL    extern inline
#endif

#define SK_PRIVATE          static
#define SK_PRIVATE_ALL      static inline

#define SK_EOS '\0'


#endif /* __DECLS_H__ */
