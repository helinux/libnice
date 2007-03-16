
#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include "udp.h"

G_BEGIN_DECLS

typedef enum
{
  NICE_CANDIDATE_TYPE_HOST,
  NICE_CANDIDATE_TYPE_SERVER_REFLEXIVE,
  NICE_CANDIDATE_TYPE_PEER_REFLEXIVE,
  NICE_CANDIDATE_TYPE_RELAYED,
} NiceCandidateType;


typedef struct _NiceCandidate NiceCandidate;

struct _NiceCandidate
{
  NiceCandidateType type;
  guint id;
  NiceAddress addr;
  NiceAddress base_addr;
  guint32 priority;
  guint stream_id;
  guint component_id;
  // guint generation;
  // gchar *foundation;
  NiceUDPSocket sock;
  gchar username[128];
  gchar password[128];
  GSource *source;
};


NiceCandidate *
nice_candidate_new (NiceCandidateType type);

void
nice_candidate_free (NiceCandidate *candidate);

gfloat
nice_candidate_jingle_priority (NiceCandidate *candidate);

guint32
nice_candidate_ice_priority (const NiceCandidate *candidate);

G_END_DECLS

#endif /* _CANDIDATE_H */

