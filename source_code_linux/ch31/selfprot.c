STATUS_T checkAntennaStatus( ANTENNA_T antenna, MODE_T *mode )
{
  ANTENNA_STS_T retStatus;

  /* Validate the input */
  assert( validAntenna( antenna ) );
  assert( validMode( mode ) );


  /*----------------------------------------*/
  /* Internal checkAntennaStatus processing */
  /*----------------------------------------*/


  /* We may have changed modes, check it. */
  assert( validMode( mode ) );

  return retStatus;
}

