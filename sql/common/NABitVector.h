/**********************************************************************
// @@@ START COPYRIGHT @@@
//
// (C) Copyright 1996-2014 Hewlett-Packard Development Company, L.P.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// @@@ END COPYRIGHT @@@
**********************************************************************/
#ifndef NA_BITVECTOR_H
#define NA_BITVECTOR_H
/* -*-C++-*-
 *****************************************************************************
 *
 * File:         NABitVector.h
 * Description:  A bit vector
 *               Similar to NASubArray, but with no superset.
 *               
 * Created:      of course
 * Language:     C++
 *
 *
 *
 *
 *****************************************************************************
 */

// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
// A bit vector.
// The bit vector class is not a template itself, but it is implemented
// using the template for a subarray. Note that the template type does
// not matter, the choice of <CollIndex> is arbitrary. The NASubCollection
// class is a specialization of a bit vector, and the more general type
// of a bit vector is now derived from the special type. This is mostly
// for historical reasons, some day we might change this to be the other
// way round.
// -----------------------------------------------------------------------

class NABitVector : public NASubArray<CollIndex>
{
public:

  NABitVector(CollHeap *heap = NULL) :
                                    NASubArray<CollIndex>(NULL,heap) {}
  NABitVector(const NABitVector &other, CollHeap *heap=NULL) :
                                  NASubArray<CollIndex>(other, heap) {}
  void setBit(CollIndex b)                           { addElement(b); }
  void resetBit(CollIndex b)                    { subtractElement(b); }
};

#endif /* NA_BITVECTOR_H */