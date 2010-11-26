#ifndef CPHONESTATE_H
#define CPHONESTATE_H

/**
  * @file
  * @author Alex <S1010455011@students.fh-hagenberg.at>
  * @version 1.0
  *
  * @section Description
  *
  * manages the state of the phone
  */

class CPhoneState
{
public:
    /**
      *phone states
      */
    enum PhoneState {OFFLINE, ONLINE, CALL};
    /**
      *set phone state
      * @param _state - phone state
      */
    void setPhoneState( CPhoneState::PhoneState _state ){ state = _state;}
    /**
      *get phone state
      * @return state - phone sate
      */
    CPhoneState::PhoneState getPhoneState(){return state;}
private:
    CPhoneState::PhoneState state;
};

#endif // CPHONESTATE_H
