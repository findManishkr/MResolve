  for( int i = 2; i <= N; i++){

       box[i] = l(i) + box[i-1] - r[i-1];

       }