#ifndef UTIL_LINUX_FGETWC_OR_ERR_H
#define UTIL_LINUX_FGETWC_OR_ERR_H

#include "c.h"
#include "nls.h"
#include "widechar.h"

static inline wint_t fgetwc_or_err(FILE *stream) {
	wint_t ret;

	errno = 0;
	ret = fgetwc(stream);
	if (ret == WEOF && errno != 0)
		err(EXIT_FAILURE, _("fgetwc() failed"));

	return ret;
}

#endif /* _FGETWC_OR_ERR_H */
