#include <iostream>
#include <lcm/lcm-cpp.hpp>
#include "lcmt_contact_results_for_viz.hpp"

class Handler
{
public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer* rbuf,
                       const std::string& chan,
                       const lcmt_contact_results_for_viz* msg)
    {
        l_x_t = 0.0;
        l_y_t = 0.0;
        l_z_t = 0.0;
        r_x_t = 0.0;
        r_y_t = 0.0;
        r_z_t = 0.0;
        for (int i = 0; i < msg->num_point_pair_contacts; ++i) {
            if(msg->point_pair_contact_info[i].contact_point[1] > 0.0){
                l_x_t += msg->point_pair_contact_info[i].contact_force[0];
                l_y_t += msg->point_pair_contact_info[i].contact_force[1];
                l_z_t += msg->point_pair_contact_info[i].contact_force[2];
            }else{
                r_x_t += msg->point_pair_contact_info[i].contact_force[0];
                r_y_t += msg->point_pair_contact_info[i].contact_force[1];
                r_z_t += msg->point_pair_contact_info[i].contact_force[2];
            }

        }
        std::cout<<l_x_t<<" "<<l_y_t<<" "<<l_z_t<<" "<<r_x_t<<" "<<r_y_t<<" "<<r_z_t<<std::endl;
    }

private:
    int counter_{0};
    double r_x{0.0};
    double r_y{0.0};
    double r_z{0.0};
    double l_x{0.0};
    double l_y{0.0};
    double l_z{0.0};
    double r_x_t{0.0};
    double r_y_t{0.0};
    double r_z_t{0.0};
    double l_x_t{0.0};
    double l_y_t{0.0};
    double l_z_t{0.0};
};

int main() {
    lcm::LCM lcm;
    if(!lcm.good())
        return 1;
    Handler handlerObject;
    lcm.subscribe("CASSIE_CONTACT_DRAKE", &Handler::handleMessage, &handlerObject);
    while(0 == lcm.handle());
    return 0;
}
