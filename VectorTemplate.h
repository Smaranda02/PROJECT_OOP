//
// Created by smaranda on 1/23/2023.
//

#ifndef OOP_VECTORTEMPLATE_H
#define OOP_VECTORTEMPLATE_H

#endif //OOP_VECTORTEMPLATE_H
#include <vector>
#include <iostream>
#include <memory>


template <class T>
class VectorTemplate{
private:
    std::vector<std::shared_ptr<T>> vector;

public:

    std::vector<std::shared_ptr<T>> getVector() const{
        return vector;
    }

    friend std::ostream &operator<<([[maybe_unused]] std::ostream &os, [[maybe_unused]] const VectorTemplate &aTemplate) {

        os << "vector: "<<std::endl;
        for([[maybe_unused]] const auto& i : aTemplate)
            os<<*i<<" ";

        return os;
    }

/*
    VectorTemplate& operator=(const VectorTemplate<T> other)
    {
        using::std::swap;
        swap(*this,other);
        return *this;
    }
*/

    //VectorTemplate(const std::vector<std::shared_ptr<T>> &other){}



    VectorTemplate()=default;

};

