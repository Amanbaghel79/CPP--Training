// Sleep is:
// i am done with my timeslice and plz dont give me another one for at least n milli seconds.
// this  OS dont even try to schedule the sleeping thread untill request thread has passed.
// 1. It will kepp the lock and sleep
// 2. it is cant be used for sync.
//

// Wait is:
// i am done with my timeslice and plz dont give me another timeslice until somecall notify() or notify_all()
// 1. it release the lock and wait.