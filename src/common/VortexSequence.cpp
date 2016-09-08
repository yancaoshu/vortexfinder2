#include "VortexSequence.h"
#include <cassert>

#if WITH_PROTOBUF
#include "VortexSequence.pb.h"
#endif

bool SerializeVortexSequence(const std::vector<VortexSequence>& seqs, std::string& buf)
{
#if WITH_PROTOBUF
  PBVortexSequences pb;
  for (int i=0; i<seqs.size(); i++) {
    PBVortexSequence *seq = pb.add_seqs();
    seq->set_its(seqs[i].its); 
    seq->set_itl(seqs[i].itl);
    seq->set_r(seqs[i].r);
    seq->set_g(seqs[i].g);
    seq->set_b(seqs[i].b);
    for (int j=0; j<seqs[i].lids.size(); j++) 
      seq->add_lids(seqs[i].lids[j]);
  }
  pb.SerializeToString(&buf);
  return true;
#else
  assert(false);
  return false;
#endif
}

bool UnserializeVortexLines(std::vector<VortexSequence>&, const std::string& buf)
{
#if WITH_PROTOBUF
  return false;
#else
  assert(false);
  return false;
#endif
}
