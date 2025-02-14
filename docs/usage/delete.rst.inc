.. IMPORTANT: this file is auto-generated from borg's built-in help, do not edit!

.. _borg_delete:

borg delete
-----------
.. code-block:: none

    borg [common options] delete [options] [REPOSITORY_OR_ARCHIVE] [ARCHIVE...]

.. only:: html

    .. class:: borg-options-table

    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    | **positional arguments**                                                                                                                                                                                                                                            |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``REPOSITORY_OR_ARCHIVE``                         | repository or archive to delete                                                                                                   |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``ARCHIVE``                                       | archives to delete                                                                                                                |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    | **options**                                                                                                                                                                                                                                                         |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``-n``, ``--dry-run``                             | do not change repository                                                                                                          |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--list``                                        | output verbose list of archives                                                                                                   |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``-s``, ``--stats``                               | print statistics for the deleted archive                                                                                          |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--cache-only``                                  | delete only the local cache for the given repository                                                                              |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--force``                                       | force deletion of corrupted archives, use ``--force --force`` in case ``--force`` does not work.                                  |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--keep-security-info``                          | keep the local security info when deleting a repository                                                                           |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--save-space``                                  | work slower, but using less space                                                                                                 |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``-c SECONDS``, ``--checkpoint-interval SECONDS`` | write checkpoint every SECONDS seconds (Default: 1800)                                                                            |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    | .. class:: borg-common-opt-ref                                                                                                                                                                                                                                      |
    |                                                                                                                                                                                                                                                                     |
    | :ref:`common_options`                                                                                                                                                                                                                                               |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    | **Archive filters** — Archive filters can be applied to repository targets.                                                                                                                                                                                         |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``-P PREFIX``, ``--prefix PREFIX``                | only consider archive names starting with this prefix. (deprecated)                                                               |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``-a GLOB``, ``--glob-archives GLOB``             | only consider archive names matching the glob. sh: rules apply (without actually using the sh: prefix), see "borg help patterns". |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--sort-by KEYS``                                | Comma-separated list of sorting keys; valid keys are: timestamp, archive, name, id; default is: timestamp                         |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--first N``                                     | consider first N archives after other filters were applied                                                                        |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+
    |                                                                             | ``--last N``                                      | consider last N archives after other filters were applied                                                                         |
    +-----------------------------------------------------------------------------+---------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------+

    .. raw:: html

        <script type='text/javascript'>
        $(document).ready(function () {
            $('.borg-options-table colgroup').remove();
        })
        </script>

.. only:: latex

    REPOSITORY_OR_ARCHIVE
        repository or archive to delete
    ARCHIVE
        archives to delete


    options
        -n, --dry-run    do not change repository
        --list          output verbose list of archives
        -s, --stats     print statistics for the deleted archive
        --cache-only    delete only the local cache for the given repository
        --force         force deletion of corrupted archives, use ``--force --force`` in case ``--force`` does not work.
        --keep-security-info    keep the local security info when deleting a repository
        --save-space    work slower, but using less space
        -c SECONDS, --checkpoint-interval SECONDS    write checkpoint every SECONDS seconds (Default: 1800)


    :ref:`common_options`
        |

    Archive filters
        -P PREFIX, --prefix PREFIX        only consider archive names starting with this prefix. (deprecated)
        -a GLOB, --glob-archives GLOB     only consider archive names matching the glob. sh: rules apply (without actually using the sh: prefix), see "borg help patterns".
        --sort-by KEYS                    Comma-separated list of sorting keys; valid keys are: timestamp, archive, name, id; default is: timestamp
        --first N                         consider first N archives after other filters were applied
        --last N                          consider last N archives after other filters were applied


Description
~~~~~~~~~~~

This command deletes an archive from the repository or the complete repository.

Important: When deleting archives, repository disk space is **not** freed until
you run ``borg compact``.

When you delete a complete repository, the security info and local cache for it
(if any) are also deleted. Alternatively, you can delete just the local cache
with the ``--cache-only`` option, or keep the security info with the
``--keep-security-info`` option.

When in doubt, use ``--dry-run --list`` to see what would be deleted.

When using ``--stats``, you will get some statistics about how much data was
deleted - the "Deleted data" deduplicated size there is most interesting as
that is how much your repository will shrink.
Please note that the "All archives" stats refer to the state after deletion.

You can delete multiple archives by specifying a shell pattern to match
multiple archives using the ``--glob-archives GLOB`` option (for more info on
these patterns, see :ref:`borg_patterns`).

To avoid accidentally deleting archives, especially when using glob patterns,
it might be helpful to use the ``--dry-run`` to test out the command without
actually making any changes to the repository.