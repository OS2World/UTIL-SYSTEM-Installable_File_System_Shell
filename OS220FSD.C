#define INCL_DOSINFOSEG
#define INCL_DOSERRORS
#define INCL_DOSFILEMGR
#define INCL_DOSINFOSEG

#include <os2.h>
#include <fsd.h>
#include <fsh.h>

int acrtused=0;         // force no runtime include
/*
 *** FSD mandatory globals to export
 */

extern ULONG FS_ATTRIBUTE;
extern CHAR FS_NAME [];

/*
 *** Globals which fsd's must export
 */

ULONG FS_ATTRIBUTE = FSA_REMOTE | FSA_UNC | FSA_LOCK;
CHAR FS_NAME [] = "TUNC1";


/***    FS_AllocatePageSpace - Adjust the size of the paging file
 *
 *      ENTRY   psffsi      = File System Independent portion of SFT
 *              psffsd      = File System Dependent portion of SFT
 *              lSize       = new size ,(in bytes)
 *              lWantContig = minimum contiguity requirement (in bytes)
 *
 *      EXIT  Returns 0 if OK
 *
 *            Returns non-zero error code if error
 ***/

int far pascal
FS_AllocatePageSpace (struct sffsi far *    psffsi,
                      struct sffsd far *    psffsd,
                      ULONG                 lSize,
                      ULONG                 lWantContig)

{
    int RetCode = ERROR_NOT_SUPPORTED;

    return RetCode;

    /* to avoid compiler warning */
    psffsi; psffsd; lSize; lWantContig;

}   /* FS_AllocatePageSpace */


/* put stand-alone fs_xxx functions in separate code segment */


int far pascal
FS_ATTACH (USHORT               flag,
           PCHAR                pDev,
           PVOID                pvpfsd,
           PVOID                pcdfsd,
           PCHAR                pParm,
           PUSHORT              pLen)
{
        return ERROR_NOT_SUPPORTED;

        flag; pDev; pvpfsd; pcdfsd; pParm; pLen;
}

int far pascal
FS_CHGFILEPTR (struct sffsi far * psffsi,
               struct sffsd far * psffsd,
               LONG offlSeek,
               USHORT type,
               USHORT IOflag)
{

    return ERROR_NOT_SUPPORTED;

    /* to prevent compiler warnings */
    IOflag; psffsi; psffsd; offlSeek; type;
}

int far pascal
FS_CHDIR (flag, pcdfsi, pcdfsd, pDir, iCurDirEnd)
USHORT                  flag;
struct cdfsi far *      pcdfsi;
struct cdfsd far *      pcdfsd;
CHAR far *              pDir;
USHORT                  iCurDirEnd;
{

    return ERROR_NOT_SUPPORTED;

    /* no warnings */
    flag; pcdfsi; pcdfsd; pDir; iCurDirEnd;
}

int far pascal
FS_CLOSE (USHORT            type,
          USHORT            IOflag,
          struct sffsi far *psffsi,
          struct sffsd far *psffsd)
{
    USHORT erc = ERROR_NOT_SUPPORTED;
    return erc;

    /* for the compiler */
    type; IOflag; psffsi; psffsd;
}

int far pascal
FS_COMMIT (USHORT type,
           USHORT IOflag,
           struct sffsi far *psffsi,
           struct sffsd far *psffsd)
{
    return ERROR_NOT_SUPPORTED;

    /* to prevent W3 warnings */
    psffsi; psffsd; type; IOflag;

}

/*
 ***    FS_COPY - Not supported (yet) for HPFS (Pinball)
 *
 */

/* put stand-alone fs_xxx functions in separate code segment */

int far pascal
FS_COPY (USHORT Flag,
         struct cdfsi far * pcdfsi,
         struct cdfsd far * pcdfsd,
         PCHAR  pSrc,
         USHORT iSrcCurDirEnd,
         PCHAR  pDst,
         USHORT iDstCurDirEnd,
         USHORT nameType)
{
        return (ERROR_CANNOT_COPY);

        Flag; pcdfsi; pcdfsd; pSrc; iSrcCurDirEnd;
        pDst; iDstCurDirEnd; nameType;
}

int far pascal
FS_DELETE (pcdfsi, pcdfsd, pFile, iCurDirEnd)
struct cdfsi far *      pcdfsi;
struct cdfsd far *      pcdfsd;
char far *              pFile;
USHORT                  iCurDirEnd;
{

        return ERROR_NOT_SUPPORTED;

        pcdfsi; pcdfsd; pFile; iCurDirEnd;
}

int far pascal
FS_DOPAGEIO (struct sffsi far *        psffsi,
             struct sffsd far *        psffsd,
             struct PageCmdHeader far *pList)

{

    return ERROR_NOT_SUPPORTED;

    /* to avoid compiler warning */
    psffsi; psffsd; pList;

}   /* FS_DoPageIO */

void far pascal
FS_EXIT (USHORT uid,
         USHORT pid,
         USHORT pdb)
{
        /* to satisfy /W3 */
        uid; pid; pdb;

        /* nothing to do */
}

int far pascal
FS_FILEATTRIBUTE (flag, pcdfsi, pcdfsd, pName, iCurDirEnd, pAttr)
USHORT                  flag;
struct cdfsi far *      pcdfsi;
struct cdfsd far *      pcdfsd;
char far *              pName;
USHORT                  iCurDirEnd;
PUSHORT                 pAttr;
{

    return ERROR_NOT_SUPPORTED;

    flag; pcdfsi; pcdfsd; pName; iCurDirEnd; pAttr;
}

int far pascal
FS_CANCELLOCKREQUEST (struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           struct filelock far * pLockRange)
{
        return ERROR_NOT_SUPPORTED;

        /* for the compiler /W3 */
        psffsi; psffsd; pLockRange;
}

int far pascal
FS_FINDCLOSE (pfsfsi, pfsfsd)
struct fsfsi far * pfsfsi;
struct fsfsd far * pfsfsd;
{

    return ERROR_NOT_SUPPORTED;

    /* to prevent /W3 warnings */
    pfsfsi; pfsfsd;
}

int far pascal
FS_FINDFROMNAME (
    struct fsfsi far *  pfsfsi,
    struct fsfsd far *  pfsfsd,
    PCHAR               pbData,     /* ptr to data buffer */
    USHORT              cbData,     /* size of data buffer */
    PUSHORT             pcMatch,    /* number of matching entries returned */
    USHORT              usLevel,    /* level of info returned */
    ULONG               ulPos,      /* unused by Pinball */
    PCHAR               pbName,
    USHORT              usFlags)
{

    return ERROR_NOT_SUPPORTED;

    /* suppress warning messages */
    pfsfsi; pfsfsd; pbData; cbData; pcMatch; usLevel; ulPos; pbName; usFlags;
}

int far pascal
FS_FINDFIRST (
    struct cdfsi far *      pcdfsi,
    struct cdfsd far *      pcdfsd,
    CHAR far *              pchName,    /* search pattern (including path) */
    USHORT                  usCurDirEnd,
    USHORT                  usAttr,     /* search attrib (hidden/system/dir) */
    struct fsfsi far *      pfsfsi,
    struct fsfsd far *      pfsfsd,
    CHAR far *              pbData,     /* ptr to data buffer */
    USHORT                  cbData,     /* size of data buffer */
    USHORT far *            pcMatch,    /* # of matching entries returned */
    USHORT                  usLevel,    /* level of info returned */
    USHORT                  usFlags
)
{

    return ERROR_NOT_SUPPORTED;

    /* for the compiler  /W3 */
    pcdfsd; pfsfsi; pchName; usCurDirEnd; usAttr; pfsfsi; pfsfsd;
    pbData; cbData; pcMatch; usLevel; usFlags;
}

int far pascal
FS_FILEINFO (flag, psffsi, psffsd, level, pData, cbData, IOflag)

USHORT                  flag;
struct sffsi far *      psffsi;
struct sffsd far *      psffsd;
USHORT                  level;
char far *              pData;
USHORT                  cbData;
USHORT                  IOflag;
{

    return ERROR_NOT_SUPPORTED;

    flag; psffsi; psffsd; level; pData; cbData; IOflag;
}

/* put stand-alone fs_xxx functions in separate code segment */


int far pascal
FS_FILEIO (struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           PCHAR              pcCmdList,
           USHORT             pusCmdLen,
           PUSHORT            pusError,
           USHORT             IOflag)
{
        return ERROR_NOT_SUPPORTED;

        /* for the compiler /W3 */
        psffsi; psffsd; pcCmdList; pusCmdLen; pusError; IOflag;
}

int far pascal
FS_FLUSHBUF (hVPB, usFlag)
USHORT  hVPB;
USHORT  usFlag;         /* FLUSH_RETAIN cache data or FLUSH_DISCARD it */
{

    return ERROR_NOT_SUPPORTED;

    hVPB; usFlag;
}



int far pascal
FS_FINDNEXT (
    struct fsfsi far *  pfsfsi,
    struct fsfsd far *  pfsfsd,
    PCHAR               pbData,     /* ptr to data buffer */
    USHORT              cbData,     /* size of data buffer */
    PUSHORT             pcMatch,     /* number of matching entries returned */
    USHORT              usLevel,
    USHORT              usFlags
    )
{

    return ERROR_NOT_SUPPORTED;

    /* suppress warning messages */
    pfsfsi; pfsfsd; pbData; cbData; pcMatch; usLevel; usFlags;
}

int far pascal
FS_FSCTL (union argdat far * pArgDat,
          USHORT        usArgType,
          USHORT        usFunc,
          PCHAR         pcParm,
          USHORT        usLenParm,
          PUSHORT       pusLenParmOut,  /* len of data returned in pcParm */
          PCHAR         pcData,
          USHORT        usLenData,
          PUSHORT       pusLenDataOut)  /* len of data returned in pcData */
{
    USHORT usRet = NO_ERROR;
    return (usRet);

    /* for the compiler /W3 */
    pArgDat; usArgType; pcParm; usLenParm; usFunc; pusLenParmOut;
    pcData; usLenData; pusLenDataOut;
}

int far pascal
FS_FILELOCKS (struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           struct filelock far * pUnLockRange,
           struct filelock far * pLockRange,
           ULONG far * pEventSemHandle,
           ULONG              flags,
           ULONG        far * pPostCt)
{
        return ERROR_NOT_SUPPORTED;

        /* for the compiler /W3 */
 psffsi; psffsd; pUnLockRange; pLockRange; pEventSemHandle; flags; pPostCt;
}

int far pascal
FS_FSINFO (flag, hVPB, p, cbData, level)
USHORT          flag;
USHORT          hVPB;
CHAR far *      p;
USHORT          cbData;
USHORT          level;
{

    return ERROR_NOT_SUPPORTED;

    flag; hVPB; p; cbData; level;
}

INT far pascal
FS_INIT (PCHAR pcParm,          /* passed in from config.sys line */
         ULONG DevHelp,
         ULONG far *pMiniFSD)
{
    return NO_ERROR;

    pcParm; DevHelp; pMiniFSD;
}

int far pascal
FS_IOCTL (struct sffsi far * psffsi,
          struct sffsd far * psffsd,
          USHORT             cat,
          USHORT             func,
          PCHAR              pParm,
          USHORT             lenMaxParm,
          PUSHORT            plenInOutParm,
          PCHAR              pData,
          USHORT             lenMaxData,
          PUSHORT            plenInOutData)
{

        return ERROR_NOT_SUPPORTED;

        /* to prevent /W3 warning */
        psffsd; psffsi; cat; func; pParm; lenMaxParm; plenInOutParm;
        pData; lenMaxData; plenInOutData;
}

int far pascal
FS_MKDIR (struct cdfsi far *pcdfsi,
          struct cdfsd far *pcdfsd,
          char far *        pName,
          unsigned short    iCurDirEnd,
          char far *        pEABuf,
          unsigned short    flags)
{

    return ERROR_NOT_SUPPORTED;

    /*  Remove warning */
    pcdfsd; iCurDirEnd; pEABuf; pcdfsi; pName; flags;

}

INT far pascal
FS_MOUNT (USHORT            fsOper, /* operation requested */
          struct vpfsi far *pvpfsi, /* ptr to file sys indep part of VPB */
          struct vpfsd far *pvpfsd, /* ptr to file sys dependent part of VPB */
          SHANDLE           hVPB,   /* volume handle */
          PCHAR             pBoot)  /* pointer to sector 0 */
{
    return ERROR_NOT_SUPPORTED;
    fsOper; pvpfsi; pvpfsd; hVPB; pBoot;
}

int far pascal
FS_MOVE (struct cdfsi far *pcdfsi,
         struct cdfsd far *pcdfsd,
         PCHAR             pSrc,
         USHORT            iSrcCurDirEnd,
         PCHAR             pDst,
         USHORT            iDstCurDirEnd,
         USHORT            flags)
{

        return ERROR_NOT_SUPPORTED;

        /* to prevent /W3 warnings */
        pcdfsd; iSrcCurDirEnd; iDstCurDirEnd; pcdfsi; pSrc; pDst; flags;
}

/*
 ***    FS_NMPIPE -
 *
 */

/* put stand-alone fs_xxx functions in separate code segment */

int far pascal
FS_NMPIPE (struct sffsi far *  pfsfsi,
           struct sffsd far *  pfsfsd,
           USHORT              OpType,
           union npoper far *  pOpRec,
           PCHAR               pData,
           PCHAR               pName)
{
        return ERROR_NOT_SUPPORTED;
        pfsfsi; pfsfsd; OpType; pOpRec; pData; pName;
}

int far pascal
FS_NEWSIZE (psffsi, psffsd, len, IOflag)
struct sffsi far *      psffsi;
struct sffsd far *      psffsd;
ULONG                   len;
USHORT                  IOflag;
{

    return ERROR_NOT_SUPPORTED;

    psffsi; psffsd; len; IOflag;

}
/*
 ***    fs_notfy.c - FS_FINDNOTIFY routines
 *
 *      Copyright Microsoft, 1988.
 */

int far pascal
FS_FINDNOTIFYCLOSE(USHORT handle)
{

    return ERROR_NOT_SUPPORTED;
    handle;
}

int far pascal
FS_FINDNOTIFYFIRST(struct cdfsi far *pcdfsi,
                   struct cdfsd far *pcdfsd,
                   PCHAR  pName,
                   USHORT iCurDirEnd,
                   USHORT attr,
                   USHORT far *pHandle,
                   PCHAR  pData,
                   USHORT cbData,
                   USHORT far *pcMatch,
                   USHORT level,
                   ULONG timeout)
{

    return ERROR_NOT_SUPPORTED;

    /* to shutup -W3 warnings */
    pcdfsd; iCurDirEnd; pData; cbData; pcdfsi; pName; attr; pHandle ;
    pcMatch; level; timeout;

}


int far pascal
FS_FINDNOTIFYNEXT(USHORT handle,
                  PCHAR  pData,
                  USHORT cbData,
                  USHORT far *pcMatch,
                  USHORT level,
                  ULONG  timeout)
{
    INT iRet = ERROR_NOT_SUPPORTED;

    return iRet;

    /* to shutup -W3 warnings */
    pData; cbData; level; handle; pcMatch; timeout;

}

int far pascal
FS_OPENCREATE (pcdfsi, pcdfsd, pcName, usCurDirEnd, psffsi, psffsd, ulOpenMode,
              usOpenFlag, pusRetAction, usAttr, pcEABuf, pfGenFlag)
struct cdfsi far *      pcdfsi;         /* File system indep. directory */
struct cdfsd far *      pcdfsd;         /* file system dep. directory   */
PCHAR                   pcName;         /* canonicalized file name      */
USHORT                  usCurDirEnd;    /* index of end of cur dir in pcName */
struct sffsi far *      psffsi;         /* file sys indep open file     */
struct sffsd far *      psffsd;         /* file sys depend open file    */
ULONG                   ulOpenMode;     /* sharing and access mode      */
USHORT                  usOpenFlag;     /* action if present or absent  */
PUSHORT                 pusRetAction;   /* return for action code       */
USHORT                  usAttr;         /* file attributes              */
PCHAR                   pcEABuf;        /* Extended Attribute buffer    */
PUSHORT                 pfGenFlag;      /* return for Need eas bit      */
{
        return ERROR_NOT_SUPPORTED;

        /* to satisfy /W3 */

 pcdfsi; pcdfsd; usCurDirEnd; pcName; psffsi; psffsd; ulOpenMode; usOpenFlag;
 pusRetAction; usAttr; pcEABuf; pfGenFlag;

}


int far pascal
FS_OPENPAGEFILE (PULONG             pFlags,     /* FirstOpen, Phys/Virt-Addr */
                 PULONG             pcMaxReq,   /* returned max req list len */
                 PCHAR              pName,      /* Name of page file */
                 struct sffsi far * psffsi,     /* sft - fs independent */
                 struct sffsd far * psffsd,     /* sft - fs dependent */
                 USHORT             OpenMode,   /* for open/create */
                 USHORT             OpenFlag,   /* for open/create */
                 USHORT             Attr,       /* for open/create */
                 ULONG              Reserved)



{
    return ERROR_NOT_SUPPORTED;

    /* to avoid compiler warning */
Reserved; pFlags; pcMaxReq; pName; psffsi; psffsd; OpenMode; OpenFlag; Attr;

}   /* FS_OPENPAGEFILE */

/*
 ***    FS_PROCESSNAME - Process the filename to be Pinball Legal
 *
 *      This routine allows the FSD to enforce a different
 *      naming convention than OS/2.
 *
 *      ENTRY   pNameBuf = pointer to ASCIIA pathname.
 *
 *      EXIT    Returns NO_ERROR
 */

int far pascal
FS_PROCESSNAME (PCHAR pNameBuf)   /* Path string to be processed */
{
        /*
         * Since Pinball is a true OS/2 file system, we don't need
         * to change anything.
         */
        return (NO_ERROR);

        /* Get rid of unreferenced formal parameter warning */
        pNameBuf;
}

int far pascal
FS_PATHINFO (flag, pcdfsi, pcdfsd, pName, iCurDirEnd, level, pData, cbData)
USHORT                  flag;
struct cdfsi far *      pcdfsi;
struct cdfsd far *      pcdfsd;
PCHAR                   pName;
USHORT                  iCurDirEnd;
USHORT                  level;
PCHAR                   pData;
USHORT                  cbData;
{
    USHORT erc = ERROR_NOT_SUPPORTED;

    return erc;

    pcdfsi; pcdfsd; iCurDirEnd; flag; pName; level; pData; cbData;
}


int far pascal
FS_READ (psffsi, psffsd, pcData, pusLen, IOflag)
struct sffsi far        *psffsi;
struct sffsd far        *psffsd;
CHAR far                *pcData;
USHORT far              *pusLen;
USHORT                  IOflag;
{
        USHORT usRet = ERROR_NOT_SUPPORTED;

        return (usRet);

        /* to prevent compiler warnings */
        IOflag; psffsi; psffsd; pcData; pusLen;
}

int far pascal
FS_RMDIR (pcdfsi, pcdfsd, pName, iCurDirEnd)
struct cdfsi far *      pcdfsi;
struct cdfsd far *      pcdfsd;
char far *              pName;
unsigned short          iCurDirEnd;
{
        USHORT usRet = ERROR_NOT_SUPPORTED;


        return (usRet);

        /* to prevent /W3 warnings */
        pcdfsd; iCurDirEnd; pName; iCurDirEnd;
}

/* put stand-alone fs_xxx functions in separate code segment */

int far pascal
FS_SETSWAP (struct sffsi far * psffsi,
            struct sffsd far * psffsd)
{

    /*
     * Just return no error.  Since we always mark pinball segments
     * non-swappable, we don't need to do anything here.
     */
    return (NO_ERROR);

    psffsi; psffsd;
}

int far pascal
FS_SHUTDOWN (usType, ulReserved)
USHORT usType;
ULONG ulReserved;
{
    INT iRet = ERROR_NOT_SUPPORTED;


    return (iRet);

    /* for warning level 3 */
    ulReserved; usType;
}

int far pascal
FS_WRITE (psffsi, psffsd, pcData, pusLen, IOflag)
struct sffsi far *      psffsi;
struct sffsd far *      psffsd;
CHAR far *              pcData;
USHORT far *            pusLen;
USHORT IOflag;
{

        return ERROR_NOT_SUPPORTED;

        psffsi; psffsd; pcData; pusLen; IOflag;
}
