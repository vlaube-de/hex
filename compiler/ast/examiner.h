#include "examinable.h"

#ifndef _EXAMINER_H_
#define _EXAMINER_H_

// forward declaration.
typedef class _Examiner {
public:
  bool examine(Examinable *a, Examinable *b);
} * Examiner;

typedef class _EqualsExaminer : public _Examiner {
public:
  bool examine(Examinable* a, Examinable* b);
} * EqualsExaminer;

typedef class _EquivalentExaminer : public _Examiner {
public:
  bool examine(Examinable* a, Examinable* b);
} * EquivalentExaminer;

typedef class _IsomorphicExaminer : public _Examiner {
public:
  bool examine(Examinable*a, Examinable* b);
} * IsomorphicExaminer;


class Examiners {
public:

  static EqualsExaminer Equals;
  static IsomorphicExaminer Isomorphic;
  static EquivalentExaminer Equivalent;
};

EqualsExaminer Examiners::Equals;
IsomorphicExaminer Examiners::Isomorphic;
EquivalentExaminer Examiners::Equivalent;


#endif /* _EXAMINER_H_ */
