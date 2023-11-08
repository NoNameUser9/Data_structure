#pragma once
#include "../binary_tree/binary_tree.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "typedef.h"


void drawBinaryTree(cv::Mat& image, Node<my_type>* node, const unsigned int x, const unsigned int y, const unsigned int level, const size_t& size) {
    if (node == nullptr)
        return;
    
    unsigned int radius = 20;
    unsigned int spacing = 50;
    double scaleY = 1;
    size_t xs = 1;
    for (size_t i = 1; i < size;)
        i *= ++xs;
    
    double scaleX = std::pow(3,xs);
    // Отображение текущего узла
    const cv::Point center(static_cast<int>(x), static_cast<int>(y));
    
    // Вычисление координат следующего уровня
    unsigned int nextLevelY = y + static_cast<unsigned int>(spacing * scaleY);
    unsigned int nextLevelXSpacing =  static_cast<unsigned int>(static_cast<double>(xs) /static_cast<double>(1 << level) * scaleX);
    
    // Отображение левого поддерева и стрелки
    if (node->left != nullptr)
    {
        unsigned int leftChildX = x - nextLevelXSpacing;
        unsigned int leftChildY = nextLevelY;
    // drawBinaryTree(image, node->get_left(), x - nextLevelXSpacing, nextLevelY, level + 1);
        cv::line(image, center, cv::Point(static_cast<int>(leftChildX), static_cast<int>(leftChildY)), cv::Scalar(0, 0, 0), 2);
        cv::circle(image, center, static_cast<int>(radius), cv::Scalar(0, 0, 0), -1);
        cv::putText(image, std::to_string(node->data), cv::Point(static_cast<int>(x - radius / 2), static_cast<int>(y)), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);
    
        drawBinaryTree(image, node->left, leftChildX, leftChildY, level + 1, size);
    }
    
    // Отображение правого поддерева и стрелки
    if (node->right != nullptr)
    {
        unsigned int rightChildX = x + nextLevelXSpacing;
        unsigned int rightChildY = nextLevelY;
        
        cv::line(image, center, cv::Point(static_cast<int>(rightChildX), static_cast<int>(rightChildY)), cv::Scalar(0, 0, 0), 2);
        cv::circle(image, center, static_cast<int>(radius), cv::Scalar(0, 0, 0), -1);
        cv::putText(image, std::to_string(node->data), cv::Point(static_cast<int>(x - radius / 2), static_cast<int>(y)), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);
    
        drawBinaryTree(image, node->right, rightChildX, rightChildY, level + 1, size);
    }

    if (node->left == nullptr && node->left == nullptr)
    {
        cv::circle(image, center, static_cast<int>(radius), cv::Scalar(0, 0, 0), -1);
        cv::putText(image, std::to_string(node->data), cv::Point(static_cast<int>(x - radius / 2), static_cast<int>(y)), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);
    }
    
    // Отображение правого поддерева
    // drawBinaryTree(image, node->get_right(), x + nextLevelXSpacing, nextLevelY, level + 1);
}
