#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
struct OneNote{
    std::string FIO, nameOfStreet;
	int nOfBuilding, nOfAppartament;
	int dateOfBirthday[3];

    friend bool operator<(const OneNote l, const OneNote r){
        if(l.FIO.compare(r.FIO)<0){
            return true;
        }
        if(l.FIO.compare(r.FIO)==0){
            if(l.nameOfStreet.compare(r.nameOfStreet)<0){
                return true;
            }
            if(l.nameOfStreet.compare(r.nameOfStreet)==0){
                if(l.nOfBuilding<r.nOfBuilding){
                    return true;
                }
                if(l.nOfBuilding==r.nOfBuilding){
                    if(l.nOfAppartament<r.nOfAppartament){
                        return true;
                    }
                    if(l.nOfAppartament==r.nOfAppartament){
                        if(l.dateOfBirthday[2]-r.dateOfBirthday[2]>0){
                            return true;
                        }
                        if(l.dateOfBirthday[2]-r.dateOfBirthday[2]==0){
                            if(l.dateOfBirthday[1]<r.dateOfBirthday[1]){
                                return true;
                            }
                            if(l.dateOfBirthday[1]==r.dateOfBirthday[1]){
                                if(l.dateOfBirthday[0]<r.dateOfBirthday[0]){
                                    return true;
                                }
                                else{
                                    return false;
                                }

                            }

                        }

                    }
                }
            }
            
        }
    }
friend bool operator>(const OneNote l, const OneNote r){
        if(l.FIO.compare(r.FIO)>0){
            return true;
        }
       	if(l.FIO.compare(r.FIO)==0){
            if(l.nameOfStreet.compare(r.nameOfStreet)>0){
                return true;
            }
            if(l.nameOfStreet.compare(r.nameOfStreet)==0){
                if(l.nOfBuilding>r.nOfBuilding){
                    return true;
                }
                if(l.nOfBuilding==r.nOfBuilding){
                    if(l.nOfAppartament>r.nOfAppartament){
                        return true;
                    }
                    if(l.nOfAppartament==r.nOfAppartament){
                        if(l.dateOfBirthday[2]-r.dateOfBirthday[2]<0){
                            return true;
                        }
                        if(l.dateOfBirthday[2]-r.dateOfBirthday[2]==0){
                            if(l.dateOfBirthday[1]>r.dateOfBirthday[1]){
                                return true;
                            }
                            if(l.dateOfBirthday[1]==r.dateOfBirthday[1]){
                                if(l.dateOfBirthday[0]>r.dateOfBirthday[0]){
                                    return true;
                                }
				else{
					return false;
				}

                            }

                        }

                    }
                }
            }
            
        }
    }
      friend bool operator>=(const OneNote& l, const OneNote& r){
        return !(l<r);
    }

    friend bool operator<=(const OneNote& l, const OneNote& r){
        return !(l>r);
    }

    friend bool operator==(const OneNote& l, const OneNote& r){
        return !(l<r) && !(l>r);
    }   

    friend std::ostream& operator<<(std::ostream& os , const OneNote& onenote){
    std::cout<< onenote.FIO<< " " << onenote.nameOfStreet<< " "<< onenote.nOfBuilding<< " "<<onenote.nOfAppartament<< " "<< onenote.dateOfBirthday[0]<<"."<<onenote.dateOfBirthday[1]<<"."<<onenote.dateOfBirthday[2]<< "\n";
    }

};

int main(){

    std::fstream file;
    file.open("listec.txt",std::fstream::in);
	if(!(file.is_open())){
		return 1;
	}
	else{
        std::cout<< "opened\n";
		std::vector<OneNote> Notes;
		while(!(file.eof())){
            char tmpIn[256];
			OneNote tmp = OneNote();
            file.getline(tmpIn,256,',');
            tmp.FIO = tmpIn;
            file.getline(tmpIn,256,',');
            tmp.nameOfStreet = tmpIn;
            file.getline(tmpIn,256,',');
            tmp.nOfBuilding = atoi(tmpIn);
            file.getline(tmpIn,256,',');
            tmp.nOfAppartament = atoi(tmpIn);
            file.getline(tmpIn,256,'.');
            tmp.dateOfBirthday[0]=atoi(tmpIn);
            file.getline(tmpIn,256,'.');
            tmp.dateOfBirthday[1]=atoi(tmpIn);
            file.getline(tmpIn,256);
            tmp.dateOfBirthday[2]=atoi(tmpIn);
			Notes.push_back(tmp);
        //    std::this_thread::sleep_for(std::chrono::seconds(1));
            //std::cout<< tmp.FIO<< " " << tmp.nameOfStreet<< " "<< tmp.nOfBuilding<< " "<<tmp.nOfAppartament<< " "<< tmp.dateOfBirthday<<"\n";
            std::cout<<tmp<<std::endl;
		//	~tmp();
		}
	    file.close();
        std::vector<OneNote>::iterator it; 
        for (it=Notes.begin();it<Notes.end();it++){
            std::cout<< *it << ' ';
        }
        std::cout<<typeid(Notes[0]).name()<<std::endl;
        std::cout<<(Notes[0]==  Notes[1]);
        
        //sorting by inserting
//        for(unsigned  i = 0; i<Notes.size();++i){
//            int tmp = i;
//    //        std::cout<< Notes.size()<<std::endl;
//            for(unsigned  j =Notes.size(); j>0;--j){
//                if((j<i)and (Notes[i]<Notes[j]) ){
//                    tmp = j;
//            }
//                
//            }
//            if (tmp!=i){
//                    it = Notes.begin();
//                    Notes.insert(it+tmp,Notes[i]);
//                    Notes.erase(it+i+1);
//                }
//    
//            }
            
	//sorting by shake
	for(std::size_t il = 0, ir = Notes.size()-1; il<ir;){
		for(std::size_t j = il;j<ir;j++ ){
			if(Notes[j+1]<Notes[j]){
				std::swap(Notes[j+1],Notes[j]);
			}
		}
		ir--;

		for(std::size_t j=ir;j>il;j--){
			if(Notes[j-1]>Notes[j]){
				std::swap(Notes[j-1],Notes[j]);
			}
		}
		il++;
	}
	for (it=Notes.begin();it<Notes.end();it++){
                std::cout<< *it << ' ';    
	    
        
	    }

	}
}
