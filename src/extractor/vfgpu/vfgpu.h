#ifndef _EXTRACTOR_CUH
#define _EXTRACTOR_CUH

#include "def.h"

typedef struct {
  int fid; 
  int chirality;
  float pos[3];
} gpu_pf_t; // punctured faces from GPU output, 16 bytes

typedef struct {
  int eid;
  int chirality;
} gpu_pe_t;

typedef struct {
  int d[3];
  int count; // d[0]*d[1]*d[2];
  bool pbc[3];
  float origins[3];
  float lengths[3];
  float cell_lengths[3];
  float B[3];
  float Kx;
} gpu_hdr_t;

struct ctx_vfgpu_t;

void vfgpu_create_context(ctx_vfgpu_t **ctx); // TODO: make vfgpu a standalone library for future use
void vfgpu_destroy_context(ctx_vfgpu_t **ctx); // TODO

void vfgpu_upload_data(
    int slot,
    const gpu_hdr_t &h, 
    const float *re, 
    const float *im);

void vfgpu_destroy_data();

void vfgpu_rotate_timesteps();

void vfgpu_extract_faces(int slot, int *pfcount, gpu_pf_t **pfbuf, int meshtype=GLGPU3D_MESH_HEX);

void vfgpu_extract_edges(int *pecount_, gpu_pe_t **pebuf_, int meshtype=GLGPU3D_MESH_HEX);

#endif
