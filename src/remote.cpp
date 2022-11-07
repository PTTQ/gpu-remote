//
// Created by win on 2022/11/7.
//

#include <cuda.h>
#include <dlfcn.h>
#include <cstring>
#include <iostream>
#include <string>

extern "C" {
void *__libc_dlsym(void *map, const char *name);
}
extern "C" {
void *__libc_dlopen_mode(const char *name, int mode);
}

#define STRINGIFY(x) #x
#define CUDA_SYMBOL_STRING(x) STRINGIFY(x)

typedef void *(*fnDlsym)(void *, const char *);

static void *real_dlsym(void *handle, const char *symbol) {
  static fnDlsym internal_dlsym = (fnDlsym) __libc_dlsym(__libc_dlopen_mode("libdl.so.2", RTLD_LAZY), "dlsym");
  return (*internal_dlsym)(handle, symbol);
}

void info(std::string info) {
  printf("Info: %s\n", info.c_str());
}

void fatal(std::string fatal) {
  printf("Fatal: %s\n", fatal.c_str());
  exit(-1);
}

void *dlsym(void *handle, const char *symbol) {

  if (strncmp(symbol, "cu", 2) != 0) {
    return (real_dlsym(handle, symbol));
  }

  if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetErrorString)) == 0) {
    return (void *) (&cuGetErrorString);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetErrorName)) == 0) {
    return (void *) (&cuGetErrorName);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuInit)) == 0) {
    return (void *) (&cuInit);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDriverGetVersion)) == 0) {
    return (void *) (&cuDriverGetVersion);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGet)) == 0) {
    return (void *) (&cuDeviceGet);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetCount)) == 0) {
    return (void *) (&cuDeviceGetCount);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetName)) == 0) {
    return (void *) (&cuDeviceGetName);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetUuid)) == 0) {
    return (void *) (&cuDeviceGetUuid);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetLuid)) == 0) {
    return (void *) (&cuDeviceGetLuid);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceTotalMem)) == 0) {
    return (void *) (&cuDeviceTotalMem);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetTexture1DLinearMaxWidth)) == 0) {
    return (void *) (&cuDeviceGetTexture1DLinearMaxWidth);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetAttribute)) == 0) {
    return (void *) (&cuDeviceGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetNvSciSyncAttributes)) == 0) {
    return (void *) (&cuDeviceGetNvSciSyncAttributes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetProperties)) == 0) {
    return (void *) (&cuDeviceGetProperties);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceComputeCapability)) == 0) {
    return (void *) (&cuDeviceComputeCapability);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxRetain)) == 0) {
    return (void *) (&cuDevicePrimaryCtxRetain);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxRelease)) == 0) {
    return (void *) (&cuDevicePrimaryCtxRelease);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxSetFlags)) == 0) {
    return (void *) (&cuDevicePrimaryCtxSetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxGetState)) == 0) {
    return (void *) (&cuDevicePrimaryCtxGetState);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxReset)) == 0) {
    return (void *) (&cuDevicePrimaryCtxReset);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxCreate)) == 0) {
    return (void *) (&cuCtxCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDestroy)) == 0) {
    return (void *) (&cuCtxDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxPushCurrent)) == 0) {
    return (void *) (&cuCtxPushCurrent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxPopCurrent)) == 0) {
    return (void *) (&cuCtxPopCurrent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetCurrent)) == 0) {
    return (void *) (&cuCtxSetCurrent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetCurrent)) == 0) {
    return (void *) (&cuCtxGetCurrent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetDevice)) == 0) {
    return (void *) (&cuCtxGetDevice);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetFlags)) == 0) {
    return (void *) (&cuCtxGetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSynchronize)) == 0) {
    return (void *) (&cuCtxSynchronize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetLimit)) == 0) {
    return (void *) (&cuCtxSetLimit);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetLimit)) == 0) {
    return (void *) (&cuCtxGetLimit);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetCacheConfig)) == 0) {
    return (void *) (&cuCtxGetCacheConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetCacheConfig)) == 0) {
    return (void *) (&cuCtxSetCacheConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetSharedMemConfig)) == 0) {
    return (void *) (&cuCtxGetSharedMemConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetSharedMemConfig)) == 0) {
    return (void *) (&cuCtxSetSharedMemConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetApiVersion)) == 0) {
    return (void *) (&cuCtxGetApiVersion);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetStreamPriorityRange)) == 0) {
    return (void *) (&cuCtxGetStreamPriorityRange);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxResetPersistingL2Cache)) == 0) {
    return (void *) (&cuCtxResetPersistingL2Cache);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxAttach)) == 0) {
    return (void *) (&cuCtxAttach);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDetach)) == 0) {
    return (void *) (&cuCtxDetach);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoad)) == 0) {
    return (void *) (&cuModuleLoad);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadData)) == 0) {
    return (void *) (&cuModuleLoadData);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadDataEx)) == 0) {
    return (void *) (&cuModuleLoadDataEx);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadFatBinary)) == 0) {
    return (void *) (&cuModuleLoadFatBinary);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleUnload)) == 0) {
    return (void *) (&cuModuleUnload);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetFunction)) == 0) {
    return (void *) (&cuModuleGetFunction);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetGlobal)) == 0) {
    return (void *) (&cuModuleGetGlobal);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetTexRef)) == 0) {
    return (void *) (&cuModuleGetTexRef);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetSurfRef)) == 0) {
    return (void *) (&cuModuleGetSurfRef);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkCreate)) == 0) {
    return (void *) (&cuLinkCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkAddData)) == 0) {
    return (void *) (&cuLinkAddData);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkAddFile)) == 0) {
    return (void *) (&cuLinkAddFile);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkComplete)) == 0) {
    return (void *) (&cuLinkComplete);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkDestroy)) == 0) {
    return (void *) (&cuLinkDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetInfo)) == 0) {
    return (void *) (&cuMemGetInfo);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAlloc)) == 0) {
    return (void *) (&cuMemAlloc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocPitch)) == 0) {
    return (void *) (&cuMemAllocPitch);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemFree)) == 0) {
    return (void *) (&cuMemFree);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAddressRange)) == 0) {
    return (void *) (&cuMemGetAddressRange);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocHost)) == 0) {
    return (void *) (&cuMemAllocHost);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemFreeHost)) == 0) {
    return (void *) (&cuMemFreeHost);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostAlloc)) == 0) {
    return (void *) (&cuMemHostAlloc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostGetDevicePointer)) == 0) {
    return (void *) (&cuMemHostGetDevicePointer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostGetFlags)) == 0) {
    return (void *) (&cuMemHostGetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocManaged)) == 0) {
    return (void *) (&cuMemAllocManaged);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetByPCIBusId)) == 0) {
    return (void *) (&cuDeviceGetByPCIBusId);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetPCIBusId)) == 0) {
    return (void *) (&cuDeviceGetPCIBusId);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcGetEventHandle)) == 0) {
    return (void *) (&cuIpcGetEventHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcOpenEventHandle)) == 0) {
    return (void *) (&cuIpcOpenEventHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcGetMemHandle)) == 0) {
    return (void *) (&cuIpcGetMemHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcOpenMemHandle)) == 0) {
    return (void *) (&cuIpcOpenMemHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcCloseMemHandle)) == 0) {
    return (void *) (&cuIpcCloseMemHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostRegister)) == 0) {
    return (void *) (&cuMemHostRegister);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostUnregister)) == 0) {
    return (void *) (&cuMemHostUnregister);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy)) == 0) {
    return (void *) (&cuMemcpy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyPeer)) == 0) {
    return (void *) (&cuMemcpyPeer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoD)) == 0) {
    return (void *) (&cuMemcpyHtoD);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoH)) == 0) {
    return (void *) (&cuMemcpyDtoH);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoD)) == 0) {
    return (void *) (&cuMemcpyDtoD);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoA)) == 0) {
    return (void *) (&cuMemcpyDtoA);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoD)) == 0) {
    return (void *) (&cuMemcpyAtoD);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoA)) == 0) {
    return (void *) (&cuMemcpyHtoA);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoH)) == 0) {
    return (void *) (&cuMemcpyAtoH);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoA)) == 0) {
    return (void *) (&cuMemcpyAtoA);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2D)) == 0) {
    return (void *) (&cuMemcpy2D);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2DUnaligned)) == 0) {
    return (void *) (&cuMemcpy2DUnaligned);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3D)) == 0) {
    return (void *) (&cuMemcpy3D);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DPeer)) == 0) {
    return (void *) (&cuMemcpy3DPeer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAsync)) == 0) {
    return (void *) (&cuMemcpyAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyPeerAsync)) == 0) {
    return (void *) (&cuMemcpyPeerAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoDAsync)) == 0) {
    return (void *) (&cuMemcpyHtoDAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoHAsync)) == 0) {
    return (void *) (&cuMemcpyDtoHAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoDAsync)) == 0) {
    return (void *) (&cuMemcpyDtoDAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoAAsync)) == 0) {
    return (void *) (&cuMemcpyHtoAAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoHAsync)) == 0) {
    return (void *) (&cuMemcpyAtoHAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2DAsync)) == 0) {
    return (void *) (&cuMemcpy2DAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DAsync)) == 0) {
    return (void *) (&cuMemcpy3DAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DPeerAsync)) == 0) {
    return (void *) (&cuMemcpy3DPeerAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD8)) == 0) {
    return (void *) (&cuMemsetD8);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD16)) == 0) {
    return (void *) (&cuMemsetD16);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD32)) == 0) {
    return (void *) (&cuMemsetD32);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D8)) == 0) {
    return (void *) (&cuMemsetD2D8);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D16)) == 0) {
    return (void *) (&cuMemsetD2D16);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D32)) == 0) {
    return (void *) (&cuMemsetD2D32);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD8Async)) == 0) {
    return (void *) (&cuMemsetD8Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD16Async)) == 0) {
    return (void *) (&cuMemsetD16Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD32Async)) == 0) {
    return (void *) (&cuMemsetD32Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D8Async)) == 0) {
    return (void *) (&cuMemsetD2D8Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D16Async)) == 0) {
    return (void *) (&cuMemsetD2D16Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D32Async)) == 0) {
    return (void *) (&cuMemsetD2D32Async);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayCreate)) == 0) {
    return (void *) (&cuArrayCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayGetDescriptor)) == 0) {
    return (void *) (&cuArrayGetDescriptor);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayGetSparseProperties)) == 0) {
    return (void *) (&cuArrayGetSparseProperties);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayGetSparseProperties)) == 0) {
    return (void *) (&cuMipmappedArrayGetSparseProperties);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayDestroy)) == 0) {
    return (void *) (&cuArrayDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArray3DCreate)) == 0) {
    return (void *) (&cuArray3DCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArray3DGetDescriptor)) == 0) {
    return (void *) (&cuArray3DGetDescriptor);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayCreate)) == 0) {
    return (void *) (&cuMipmappedArrayCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayGetLevel)) == 0) {
    return (void *) (&cuMipmappedArrayGetLevel);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayDestroy)) == 0) {
    return (void *) (&cuMipmappedArrayDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAddressReserve)) == 0) {
    return (void *) (&cuMemAddressReserve);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAddressFree)) == 0) {
    return (void *) (&cuMemAddressFree);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemCreate)) == 0) {
    return (void *) (&cuMemCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRelease)) == 0) {
    return (void *) (&cuMemRelease);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemMap)) == 0) {
    return (void *) (&cuMemMap);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemMapArrayAsync)) == 0) {
    return (void *) (&cuMemMapArrayAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemUnmap)) == 0) {
    return (void *) (&cuMemUnmap);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemSetAccess)) == 0) {
    return (void *) (&cuMemSetAccess);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAccess)) == 0) {
    return (void *) (&cuMemGetAccess);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemExportToShareableHandle)) == 0) {
    return (void *) (&cuMemExportToShareableHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemImportFromShareableHandle)) == 0) {
    return (void *) (&cuMemImportFromShareableHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAllocationGranularity)) == 0) {
    return (void *) (&cuMemGetAllocationGranularity);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAllocationPropertiesFromHandle)) == 0) {
    return (void *) (&cuMemGetAllocationPropertiesFromHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRetainAllocationHandle)) == 0) {
    return (void *) (&cuMemRetainAllocationHandle);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerGetAttribute)) == 0) {
    return (void *) (&cuPointerGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemPrefetchAsync)) == 0) {
    return (void *) (&cuMemPrefetchAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAdvise)) == 0) {
    return (void *) (&cuMemAdvise);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRangeGetAttribute)) == 0) {
    return (void *) (&cuMemRangeGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRangeGetAttributes)) == 0) {
    return (void *) (&cuMemRangeGetAttributes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerSetAttribute)) == 0) {
    return (void *) (&cuPointerSetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerGetAttributes)) == 0) {
    return (void *) (&cuPointerGetAttributes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCreate)) == 0) {
    return (void *) (&cuStreamCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCreateWithPriority)) == 0) {
    return (void *) (&cuStreamCreateWithPriority);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetPriority)) == 0) {
    return (void *) (&cuStreamGetPriority);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetFlags)) == 0) {
    return (void *) (&cuStreamGetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetCtx)) == 0) {
    return (void *) (&cuStreamGetCtx);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitEvent)) == 0) {
    return (void *) (&cuStreamWaitEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamAddCallback)) == 0) {
    return (void *) (&cuStreamAddCallback);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBeginCapture)) == 0) {
    return (void *) (&cuStreamBeginCapture);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuThreadExchangeStreamCaptureMode)) == 0) {
    return (void *) (&cuThreadExchangeStreamCaptureMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamEndCapture)) == 0) {
    return (void *) (&cuStreamEndCapture);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamIsCapturing)) == 0) {
    return (void *) (&cuStreamIsCapturing);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetCaptureInfo)) == 0) {
    return (void *) (&cuStreamGetCaptureInfo);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamAttachMemAsync)) == 0) {
    return (void *) (&cuStreamAttachMemAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamQuery)) == 0) {
    return (void *) (&cuStreamQuery);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamSynchronize)) == 0) {
    return (void *) (&cuStreamSynchronize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamDestroy)) == 0) {
    return (void *) (&cuStreamDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCopyAttributes)) == 0) {
    return (void *) (&cuStreamCopyAttributes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetAttribute)) == 0) {
    return (void *) (&cuStreamGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamSetAttribute)) == 0) {
    return (void *) (&cuStreamSetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventCreate)) == 0) {
    return (void *) (&cuEventCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventRecord)) == 0) {
    return (void *) (&cuEventRecord);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventRecordWithFlags)) == 0) {
    return (void *) (&cuEventRecordWithFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventQuery)) == 0) {
    return (void *) (&cuEventQuery);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventSynchronize)) == 0) {
    return (void *) (&cuEventSynchronize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventDestroy)) == 0) {
    return (void *) (&cuEventDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventElapsedTime)) == 0) {
    return (void *) (&cuEventElapsedTime);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuImportExternalMemory)) == 0) {
    return (void *) (&cuImportExternalMemory);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuExternalMemoryGetMappedBuffer)) == 0) {
    return (void *) (&cuExternalMemoryGetMappedBuffer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuExternalMemoryGetMappedMipmappedArray)) == 0) {
    return (void *) (&cuExternalMemoryGetMappedMipmappedArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDestroyExternalMemory)) == 0) {
    return (void *) (&cuDestroyExternalMemory);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuImportExternalSemaphore)) == 0) {
    return (void *) (&cuImportExternalSemaphore);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSignalExternalSemaphoresAsync)) == 0) {
    return (void *) (&cuSignalExternalSemaphoresAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuWaitExternalSemaphoresAsync)) == 0) {
    return (void *) (&cuWaitExternalSemaphoresAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDestroyExternalSemaphore)) == 0) {
    return (void *) (&cuDestroyExternalSemaphore);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitValue32)) == 0) {
    return (void *) (&cuStreamWaitValue32);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitValue64)) == 0) {
    return (void *) (&cuStreamWaitValue64);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWriteValue32)) == 0) {
    return (void *) (&cuStreamWriteValue32);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWriteValue64)) == 0) {
    return (void *) (&cuStreamWriteValue64);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBatchMemOp)) == 0) {
    return (void *) (&cuStreamBatchMemOp);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncGetAttribute)) == 0) {
    return (void *) (&cuFuncGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetAttribute)) == 0) {
    return (void *) (&cuFuncSetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetCacheConfig)) == 0) {
    return (void *) (&cuFuncSetCacheConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetSharedMemConfig)) == 0) {
    return (void *) (&cuFuncSetSharedMemConfig);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchKernel)) == 0) {
    return (void *) (&cuLaunchKernel);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchCooperativeKernel)) == 0) {
    return (void *) (&cuLaunchCooperativeKernel);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchCooperativeKernelMultiDevice)) == 0) {
    return (void *) (&cuLaunchCooperativeKernelMultiDevice);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchHostFunc)) == 0) {
    return (void *) (&cuLaunchHostFunc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetBlockShape)) == 0) {
    return (void *) (&cuFuncSetBlockShape);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetSharedSize)) == 0) {
    return (void *) (&cuFuncSetSharedSize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetSize)) == 0) {
    return (void *) (&cuParamSetSize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSeti)) == 0) {
    return (void *) (&cuParamSeti);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetf)) == 0) {
    return (void *) (&cuParamSetf);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetv)) == 0) {
    return (void *) (&cuParamSetv);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunch)) == 0) {
    return (void *) (&cuLaunch);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchGrid)) == 0) {
    return (void *) (&cuLaunchGrid);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchGridAsync)) == 0) {
    return (void *) (&cuLaunchGridAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetTexRef)) == 0) {
    return (void *) (&cuParamSetTexRef);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphCreate)) == 0) {
    return (void *) (&cuGraphCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddKernelNode)) == 0) {
    return (void *) (&cuGraphAddKernelNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeGetParams)) == 0) {
    return (void *) (&cuGraphKernelNodeGetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeSetParams)) == 0) {
    return (void *) (&cuGraphKernelNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddMemcpyNode)) == 0) {
    return (void *) (&cuGraphAddMemcpyNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemcpyNodeGetParams)) == 0) {
    return (void *) (&cuGraphMemcpyNodeGetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemcpyNodeSetParams)) == 0) {
    return (void *) (&cuGraphMemcpyNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddMemsetNode)) == 0) {
    return (void *) (&cuGraphAddMemsetNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemsetNodeGetParams)) == 0) {
    return (void *) (&cuGraphMemsetNodeGetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemsetNodeSetParams)) == 0) {
    return (void *) (&cuGraphMemsetNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddHostNode)) == 0) {
    return (void *) (&cuGraphAddHostNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphHostNodeGetParams)) == 0) {
    return (void *) (&cuGraphHostNodeGetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphHostNodeSetParams)) == 0) {
    return (void *) (&cuGraphHostNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddChildGraphNode)) == 0) {
    return (void *) (&cuGraphAddChildGraphNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphChildGraphNodeGetGraph)) == 0) {
    return (void *) (&cuGraphChildGraphNodeGetGraph);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEmptyNode)) == 0) {
    return (void *) (&cuGraphAddEmptyNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEventRecordNode)) == 0) {
    return (void *) (&cuGraphAddEventRecordNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventRecordNodeGetEvent)) == 0) {
    return (void *) (&cuGraphEventRecordNodeGetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventRecordNodeSetEvent)) == 0) {
    return (void *) (&cuGraphEventRecordNodeSetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEventWaitNode)) == 0) {
    return (void *) (&cuGraphAddEventWaitNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventWaitNodeGetEvent)) == 0) {
    return (void *) (&cuGraphEventWaitNodeGetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventWaitNodeSetEvent)) == 0) {
    return (void *) (&cuGraphEventWaitNodeSetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphClone)) == 0) {
    return (void *) (&cuGraphClone);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeFindInClone)) == 0) {
    return (void *) (&cuGraphNodeFindInClone);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetType)) == 0) {
    return (void *) (&cuGraphNodeGetType);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetNodes)) == 0) {
    return (void *) (&cuGraphGetNodes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetRootNodes)) == 0) {
    return (void *) (&cuGraphGetRootNodes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetEdges)) == 0) {
    return (void *) (&cuGraphGetEdges);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetDependencies)) == 0) {
    return (void *) (&cuGraphNodeGetDependencies);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetDependentNodes)) == 0) {
    return (void *) (&cuGraphNodeGetDependentNodes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddDependencies)) == 0) {
    return (void *) (&cuGraphAddDependencies);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphRemoveDependencies)) == 0) {
    return (void *) (&cuGraphRemoveDependencies);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphDestroyNode)) == 0) {
    return (void *) (&cuGraphDestroyNode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphInstantiate)) == 0) {
    return (void *) (&cuGraphInstantiate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecKernelNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecKernelNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecMemcpyNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecMemcpyNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecMemsetNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecMemsetNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecHostNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecHostNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecChildGraphNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecChildGraphNodeSetParams);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecEventRecordNodeSetEvent)) == 0) {
    return (void *) (&cuGraphExecEventRecordNodeSetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecEventWaitNodeSetEvent)) == 0) {
    return (void *) (&cuGraphExecEventWaitNodeSetEvent);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphUpload)) == 0) {
    return (void *) (&cuGraphUpload);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphLaunch)) == 0) {
    return (void *) (&cuGraphLaunch);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecDestroy)) == 0) {
    return (void *) (&cuGraphExecDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphDestroy)) == 0) {
    return (void *) (&cuGraphDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecUpdate)) == 0) {
    return (void *) (&cuGraphExecUpdate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeCopyAttributes)) == 0) {
    return (void *) (&cuGraphKernelNodeCopyAttributes);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeGetAttribute)) == 0) {
    return (void *) (&cuGraphKernelNodeGetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeSetAttribute)) == 0) {
    return (void *) (&cuGraphKernelNodeSetAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxActiveBlocksPerMultiprocessor)) == 0) {
    return (void *) (&cuOccupancyMaxActiveBlocksPerMultiprocessor);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags)) == 0) {
    return (void *) (&cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxPotentialBlockSize)) == 0) {
    return (void *) (&cuOccupancyMaxPotentialBlockSize);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxPotentialBlockSizeWithFlags)) == 0) {
    return (void *) (&cuOccupancyMaxPotentialBlockSizeWithFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyAvailableDynamicSMemPerBlock)) == 0) {
    return (void *) (&cuOccupancyAvailableDynamicSMemPerBlock);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetArray)) == 0) {
    return (void *) (&cuTexRefSetArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmappedArray)) == 0) {
    return (void *) (&cuTexRefSetMipmappedArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddress)) == 0) {
    return (void *) (&cuTexRefSetAddress);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddress2D)) == 0) {
    return (void *) (&cuTexRefSetAddress2D);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFormat)) == 0) {
    return (void *) (&cuTexRefSetFormat);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddressMode)) == 0) {
    return (void *) (&cuTexRefSetAddressMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFilterMode)) == 0) {
    return (void *) (&cuTexRefSetFilterMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapFilterMode)) == 0) {
    return (void *) (&cuTexRefSetMipmapFilterMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapLevelBias)) == 0) {
    return (void *) (&cuTexRefSetMipmapLevelBias);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapLevelClamp)) == 0) {
    return (void *) (&cuTexRefSetMipmapLevelClamp);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMaxAnisotropy)) == 0) {
    return (void *) (&cuTexRefSetMaxAnisotropy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetBorderColor)) == 0) {
    return (void *) (&cuTexRefSetBorderColor);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFlags)) == 0) {
    return (void *) (&cuTexRefSetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetAddress)) == 0) {
    return (void *) (&cuTexRefGetAddress);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetArray)) == 0) {
    return (void *) (&cuTexRefGetArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmappedArray)) == 0) {
    return (void *) (&cuTexRefGetMipmappedArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetAddressMode)) == 0) {
    return (void *) (&cuTexRefGetAddressMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFilterMode)) == 0) {
    return (void *) (&cuTexRefGetFilterMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFormat)) == 0) {
    return (void *) (&cuTexRefGetFormat);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapFilterMode)) == 0) {
    return (void *) (&cuTexRefGetMipmapFilterMode);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapLevelBias)) == 0) {
    return (void *) (&cuTexRefGetMipmapLevelBias);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapLevelClamp)) == 0) {
    return (void *) (&cuTexRefGetMipmapLevelClamp);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMaxAnisotropy)) == 0) {
    return (void *) (&cuTexRefGetMaxAnisotropy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetBorderColor)) == 0) {
    return (void *) (&cuTexRefGetBorderColor);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFlags)) == 0) {
    return (void *) (&cuTexRefGetFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefCreate)) == 0) {
    return (void *) (&cuTexRefCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefDestroy)) == 0) {
    return (void *) (&cuTexRefDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfRefSetArray)) == 0) {
    return (void *) (&cuSurfRefSetArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfRefGetArray)) == 0) {
    return (void *) (&cuSurfRefGetArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectCreate)) == 0) {
    return (void *) (&cuTexObjectCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectDestroy)) == 0) {
    return (void *) (&cuTexObjectDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetResourceDesc)) == 0) {
    return (void *) (&cuTexObjectGetResourceDesc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetTextureDesc)) == 0) {
    return (void *) (&cuTexObjectGetTextureDesc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetResourceViewDesc)) == 0) {
    return (void *) (&cuTexObjectGetResourceViewDesc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectCreate)) == 0) {
    return (void *) (&cuSurfObjectCreate);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectDestroy)) == 0) {
    return (void *) (&cuSurfObjectDestroy);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectGetResourceDesc)) == 0) {
    return (void *) (&cuSurfObjectGetResourceDesc);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceCanAccessPeer)) == 0) {
    return (void *) (&cuDeviceCanAccessPeer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxEnablePeerAccess)) == 0) {
    return (void *) (&cuCtxEnablePeerAccess);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDisablePeerAccess)) == 0) {
    return (void *) (&cuCtxDisablePeerAccess);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetP2PAttribute)) == 0) {
    return (void *) (&cuDeviceGetP2PAttribute);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsUnregisterResource)) == 0) {
    return (void *) (&cuGraphicsUnregisterResource);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsSubResourceGetMappedArray)) == 0) {
    return (void *) (&cuGraphicsSubResourceGetMappedArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceGetMappedMipmappedArray)) == 0) {
    return (void *) (&cuGraphicsResourceGetMappedMipmappedArray);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceGetMappedPointer)) == 0) {
    return (void *) (&cuGraphicsResourceGetMappedPointer);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceSetMapFlags)) == 0) {
    return (void *) (&cuGraphicsResourceSetMapFlags);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsMapResources)) == 0) {
    return (void *) (&cuGraphicsMapResources);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsUnmapResources)) == 0) {
    return (void *) (&cuGraphicsUnmapResources);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetExportTable)) == 0) {
    return (void *) (&cuGetExportTable);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncGetModule)) == 0) {
    return (void *) (&cuFuncGetModule);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceTotalMem)) == 0) {
    return (void *) (&cuDeviceTotalMem);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetInfo)) == 0) {
    return (void *) (&cuMemGetInfo);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocHost)) == 0) {
    return (void *) (&cuMemAllocHost);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoA)) == 0) {
    return (void *) (&cuMemcpyHtoA);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoH)) == 0) {
    return (void *) (&cuMemcpyAtoH);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoA)) == 0) {
    return (void *) (&cuMemcpyAtoA);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoAAsync)) == 0) {
    return (void *) (&cuMemcpyHtoAAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoHAsync)) == 0) {
    return (void *) (&cuMemcpyAtoHAsync);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBeginCapture)) == 0) {
    return (void *) (&cuStreamBeginCapture);
  }
  return (real_dlsym(handle, symbol));
}

typedef CUresult (*cuda_func_t)(...);

CUresult cuInit(unsigned int Flags) {
  static void *table = dlopen("libcuda.so.1", RTLD_NOW | RTLD_NODELETE);
  if (table == nullptr) {
    fatal("failed to load cuda table");
  }
  static void *real_func = (void *) real_dlsym(table, "cuInit");
  if (real_func == nullptr) {
    fatal("failed to load function cuInit");
  }
  info("loaded function cuInit");
  CUresult result = ((cuda_func_t) real_func)(Flags);
  return result;
}