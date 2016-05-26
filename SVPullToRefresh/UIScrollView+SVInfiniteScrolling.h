//
// UIScrollView+SVInfiniteScrolling.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>

@class SVInfiniteScrollingView;

@interface UIScrollView (SVInfiniteScrolling)

- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;
- (void)removeObserver;
- (void)triggerInfiniteScrolling;

@property (nonatomic, strong, readonly) SVInfiniteScrollingView *infiniteScrollingView;
@property (nonatomic, assign) BOOL showsInfiniteScrolling;

@end

/**
 *  状态
 */
typedef NS_ENUM(NSUInteger, SVInfiniteScrollingState) {
    /**
     *  空闲状态
     */
    SVInfiniteScrollingStateIdle,
    /**
     *  停止状态，需要手动触发
     */
    SVInfiniteScrollingStateStopped,
    /**
     *  触发状态
     */
    SVInfiniteScrollingStateTriggered,
    /**
     *  加载中
     */
    SVInfiniteScrollingStateLoading,
    /**
     *  到达底部
     */
    SVInfiniteScrollingStateEnd
};

@interface SVInfiniteScrollingView : UIView

@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, readonly) SVInfiniteScrollingState state;
@property (nonatomic, assign) BOOL enabled;

- (void)setCustomView:(UIView *)view forState:(SVInfiniteScrollingState)state;

- (void)startLoading;
/**
 *  完成上拉刷新
 *
 *  @param hasError YES: state -> Stopped; NO: state -> Idle
 */
- (void)stopLoading:(BOOL)hasError;
- (void)stopForEnd;

@end
