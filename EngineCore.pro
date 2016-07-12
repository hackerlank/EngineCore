TEMPLATE = subdirs

SUBDIRS += src \
    res
SUBDIRS += test


test.depend = src
