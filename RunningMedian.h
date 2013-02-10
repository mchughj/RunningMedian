#ifndef RunningMedian_h
#define RunningMedian_h
//
//    FILE: RunningMedian.h
//  AUTHOR: Rob dot Tillaart at gmail dot com
// PURPOSE: RunningMedian library for Arduino
// VERSION: 0.1.02
//     URL: http://arduino.cc/playground/Main/RunningMedian
// HISTORY: See RunningMedian.cpp
//
// Released to the public domain.
//
// Modifications by Jason McHugh.
//

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <inttypes.h>

#define RUNNINGMEDIANVERSION "0.1.03"

// The number of data samples that will be taken.  I will ensure
// that the construction of my instance lies within these boundaries.
#define MEDIAN_MIN 1
#define MEDIAN_MAX 19

/**
 * The RunningMedian class performs simple aggregations on streams of data.
 * There are two main defining characteristics.
 *
 * 1/  How many samples are used in the aggregation operations.
 * 2/  Whether or not the instance suports aggregation operations that
 *     fundamentally require sorting.  These operations are
 *         lowest, highest, and median
 *
 * When the instance does not support the aggregation operation, or if the
 * number of datapoints currently being tracked is zero, then the result of
 * the 'get' requests will be NAN.
 *
 * When the RunningMedian instance does not support the aggregation
 * operations described in #2 then it is approximately 2x more memory efficient.
 *
 */
class RunningMedian
{
    public:
        /**
          * Constructor that takes in the sample size
          * that will be used to determine the aggregate values.
          * The value that you pass in will be constrained to the
          * range [ MEDIAN_MIN, MEDIAN_MAX ].  This instance of the
          * RunningMedian can perform all operations.
          */
        RunningMedian(uint8_t size);

        /**
          * Constructor that takes in the sample size
          * that will be used to determine the aggregate values.
          * The value that you pass in will be constrained to the
          * range [ MEDIAN_MIN, MEDIAN_MAX ].
          *
          * Whether or not the instance supports aggregates that
          * requires sorting is determined by you.
          */
        RunningMedian(uint8_t size, bool supportsSortedAggregates);

        /**
          * Default constructor.  The sample size is defined by
          * MEDIAN_MAX
          */
        RunningMedian();

        ~RunningMedian();

        /**
          * Clears all datapoints and resets the counter to zero.
          */
        void clear();
        void add(float);

        /**
          * Aggregation operations will return NAN if there are no data values
          * contained within this instance.  The following aggregation operations
          * will also return NAN if this instance has been configured to not
          * support them.
          */
        float getMedian();
        float getHighest();
        float getLowest();

        /**
          * Returns the average value in the sample or NAN if there are no samples.
          */
        float getAverage();

    protected:
        uint8_t _size;
        uint8_t _cnt;
        uint8_t _idx;
        float *_ar;
        float *_as;
        void sort();
        void init( bool supportsSortedAggregates );
};

#endif

