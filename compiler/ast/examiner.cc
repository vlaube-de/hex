#include "examiner.h"

EqualsExaminer Examiners::Equals = new _EqualsExaminer();
IsomorphicExaminer Examiners::Isomorphic = new _IsomorphicExaminer();
EquivalentExaminer Examiners::Equivalent = new _EquivalentExaminer();
