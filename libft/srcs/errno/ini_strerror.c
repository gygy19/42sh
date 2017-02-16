/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_strerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:58:32 by mblet             #+#    #+#             */
/*   Updated: 2016/05/05 18:18:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>
#include <stdlib.h>

static void		s_ini_strerror4(char ***at)
{
	(*at)[EMULTIHOP] = "Multihop attempted";
	(*at)[ENODATA] = "No data available";
	(*at)[ENOLINK] = "Link has been severed";
	(*at)[ENOSR] = "Out of streams resources";
	(*at)[ENOSTR] = "Device not a stream";
	(*at)[EPROTO] = "Protocol error";
	(*at)[ETIME] = "Timer expired";
	(*at)[EOPNOTSUPP] = "Operation not supported on transport endpoint";
	(*at)[ENOPOLICY] = "";
	(*at)[ENOTRECOVERABLE] = "";
	(*at)[EOWNERDEAD] = "";
	(*at)[ELAST] = "";
}

static void		s_ini_strerror3(char ***at)
{
	(*at)[EREMOTE] = "Object is remote";
	(*at)[EBADRPC] = "";
	(*at)[ERPCMISMATCH] = "";
	(*at)[EPROGUNAVAIL] = "";
	(*at)[EPROGMISMATCH] = "";
	(*at)[EPROCUNAVAIL] = "";
	(*at)[ENOLCK] = "No record locks available";
	(*at)[ENOSYS] = "Operation not applicable";
	(*at)[EFTYPE] = "";
	(*at)[EAUTH] = "";
	(*at)[ENEEDAUTH] = "";
	(*at)[EPWROFF] = "";
	(*at)[EDEVERR] = "";
	(*at)[EOVERFLOW] = "Value too large for defined data type";
	(*at)[EBADEXEC] = "";
	(*at)[EBADARCH] = "";
	(*at)[ESHLIBVERS] = "";
	(*at)[EBADMACHO] = "";
	(*at)[ECANCELED] = "Operation canceled";
	(*at)[EIDRM] = "Identifier removed";
	(*at)[ENOMSG] = "No message of desired type";
	(*at)[EILSEQ] = "Illegal byte sequence";
	(*at)[ENOATTR] = "Attribute not found";
	(*at)[EBADMSG] = "Not a data message";
	s_ini_strerror4(at);
}

static void		s_ini_strerror2(char ***at)
{
	(*at)[EAFNOSUPPORT] = "Address family not supported by protocol";
	(*at)[EADDRINUSE] = "Address already in use";
	(*at)[EADDRNOTAVAIL] = "Cannot assign requested address";
	(*at)[ENETDOWN] = "Network is down";
	(*at)[ENETUNREACH] = "Network is unreachable";
	(*at)[ENETRESET] = "Network dropped connection because of reset";
	(*at)[ECONNABORTED] = "Software caused connection abort";
	(*at)[ECONNRESET] = "Connection reset by peer";
	(*at)[ENOBUFS] = "No buffer space available";
	(*at)[EISCONN] = "Transport endpoint is already connected";
	(*at)[ENOTCONN] = "Transport endpoint is not connected";
	(*at)[ESHUTDOWN] = "Cannot send after transport endpoint shutdown";
	(*at)[ETOOMANYREFS] = "Too many references: cannot splice";
	(*at)[ETIMEDOUT] = "Connection timed out";
	(*at)[ECONNREFUSED] = "Connection refused";
	(*at)[ELOOP] = "Too many symbolic links encountered";
	(*at)[ENAMETOOLONG] = "File name too long";
	(*at)[EHOSTDOWN] = "Host is down";
	(*at)[EHOSTUNREACH] = "No route to host";
	(*at)[ENOTEMPTY] = "Directory not empty";
	(*at)[EPROCLIM] = "";
	(*at)[EUSERS] = "Too many users";
	(*at)[EDQUOT] = "";
	(*at)[ESTALE] = "Stale NFS file handle";
	s_ini_strerror3(at);
}

static void		s_ini_strerror1(char ***at)
{
	(*at)[EINVAL] = "Invalid argument";
	(*at)[ENFILE] = "File table overflow";
	(*at)[EMFILE] = "Too many open files";
	(*at)[ENOTTY] = "Not a typewriter";
	(*at)[ETXTBSY] = "Text file busy";
	(*at)[EFBIG] = "File too large";
	(*at)[ENOSPC] = "No space left on device";
	(*at)[ESPIPE] = "Illegal seek";
	(*at)[EROFS] = "Read-only file system";
	(*at)[EMLINK] = "Too many links";
	(*at)[EPIPE] = "Broken pipe";
	(*at)[EDOM] = "Math argument out of domain of func";
	(*at)[ERANGE] = "Math result not representable";
	(*at)[EINPROGRESS] = "Operation now in progress";
	(*at)[EALREADY] = "Operation already in progress";
	(*at)[ENOTSOCK] = "Socket operation on non-socket";
	(*at)[EDESTADDRREQ] = "Destination address required";
	(*at)[EMSGSIZE] = "Message too long";
	(*at)[EPROTOTYPE] = "Protocol wrong type for socket";
	(*at)[ENOPROTOOPT] = "Protocol not available";
	(*at)[EPROTONOSUPPORT] = "Protocol not supported";
	(*at)[ESOCKTNOSUPPORT] = "Socket type not supported";
	(*at)[ENOTSUP] = "Operation not supported on transport endpoint";
	(*at)[EPFNOSUPPORT] = "Protocol family not supported";
	s_ini_strerror2(at);
}

void			ini_strerror(char ***at)
{
	if (((*at) = (char **)malloc(sizeof(char *) * 107)) == NULL)
		return ;
	(*at)[0] = "Nothing";
	(*at)[EPERM] = "Not owner";
	(*at)[ENOENT] = "No such file or directory";
	(*at)[ESRCH] = "No such process";
	(*at)[EINTR] = "Interrupted system call";
	(*at)[EIO] = "I/O error";
	(*at)[ENXIO] = "No such device or address";
	(*at)[E2BIG] = "Arg list too long";
	(*at)[ENOEXEC] = "Exec format error";
	(*at)[EBADF] = "Bad file number";
	(*at)[ECHILD] = "No child processes";
	(*at)[EDEADLK] = "Deadlock condition";
	(*at)[ENOMEM] = "Not enough space";
	(*at)[EACCES] = "Permission denied";
	(*at)[EFAULT] = "Bad address";
	(*at)[ENOTBLK] = "Block device required";
	(*at)[EBUSY] = "Device busy";
	(*at)[EEXIST] = "File exists";
	(*at)[EXDEV] = "Cross-device link";
	(*at)[ENODEV] = "No such device";
	(*at)[ENOTDIR] = "Not a directory";
	(*at)[EISDIR] = "Is a directory";
	s_ini_strerror1(at);
}
