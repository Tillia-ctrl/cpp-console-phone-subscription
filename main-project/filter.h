#ifndef FILTER_H
#define FILTER_H

#include "phone_subscription.h"

PhoneCall** filter(PhoneCall* array[], int size, bool (*check)(PhoneCall* element), int& result_size);

/*
  <function_name>:
              ,
          true,
    ,

:
    array       -
    size        -
    check       -    .

                   ,
    result_data - ,    - ,



          ,
     (     true)
*/


bool fMobileCalls(PhoneCall* element);

/*
  check_book_subscription_by_author:
      - ,

:
    element -   ,


    true,           ,  false
*/


bool fNovember2021Calls(PhoneCall* element);

/*
  check_book_subscription_by_date:
      - ,           2021-

:
    element -   ,


    true,           2021- ,  false
*/

#endif

